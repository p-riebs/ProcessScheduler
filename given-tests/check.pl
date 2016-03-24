#!/usr/bin/perl

#
# A little script to run the project and check it against the
# expected result trace.
#

use strict;

my $binary = "./scheduler";

###########################################
# Parse Command Line Arguments
# [SCHEDULER] [QUANTUM] [INPUT FILE] [EXPECTED FILE]
###########################################
if( scalar(@ARGV) < 3 ) {
    print "ERROR: Not enough arguments\n";
    exit -1;
}

my $scheduler  = int($ARGV[0]);
my $quantum    = int($ARGV[1]);
my $input_file = $ARGV[2];
my $exp_file   = $ARGV[3];
my $cmd;

if( !(-e $input_file) ) {
    print "Error: Input file does not exist ($input_file)\n";
    exit -1;
}

if( !(-e $exp_file) ) {
    print "Error: Expected file does not exist ($exp_file)\n";
    exit -2;
}


###########################################
# Diagnostics
###########################################
print "-"x70 . "\n";
print "Running the command:\n";
if( $quantum > 0 ) {
    $cmd = "$binary -s $scheduler -q $quantum $input_file";
} else {
    $cmd = "$binary -s $scheduler $input_file";
}
print "\tshell\$ $cmd\n";


###########################################
# Run the command and gather all output
###########################################
my @output;
@output = `$cmd 2>&1`;


###########################################
# Extract the values from the live run
###########################################
my $avg_waiting_time;
my $avg_turnaround_time;
my @per_process_results = ();

foreach my $line (@output) {
    chomp($line);

    if( $line =~ /# /i ) {
        if( $line =~ /waiting time/i ) {
            $line =~ /\d+\.\d+/;
            $avg_waiting_time = $&;
        }
        elsif( $line =~ /turnaround time/i ) {
            $line =~ /\d+\.\d+/;
            $avg_turnaround_time = $&;
        }
        elsif( $line =~ /\d/ ) {
            $line =~ s/#\s+//;
            push(@per_process_results, $line);
        }
    }
}

if( !defined($avg_waiting_time) ) {
    printf("Error: Average Waiting Time not found in the output!\n");
    printf("       Make sure that the program displays the string\n");
    printf("       \"Waiting Time\" followed by the average waiting\n");
    printf("       time. See assignment specification for an example.\n");
    printf("       Make sure this line is prefixed with a # symbol.\n");
    display_result(1);
    #exit 1;
    exit 0;
}

if( !defined($avg_turnaround_time) ) {
    printf("Error: Average Turnaround Time not found in the output!\n");
    printf("       Make sure that the program displays the string\n");
    printf("       \"Turnaround Time\" followed by the average turnaround\n");
    printf("       time. See assignment specification for an example.\n");
    printf("       Make sure this line is prefixed with a # symbol.\n");
    display_result(1);
    #exit 1;
    exit 0;
}

if( scalar(@per_process_results) == 0 ) {
    printf("Error: No per-process results found. Make sure the final\n");
    printf("       per-process results are prefixed with a # symbol.\n");
    display_result(1);
    #exit 1;
    exit 0;
}

###########################################
# Extract the expected values from the trace
###########################################
my $exp_waiting_time = 0;
my $exp_turnaround_time = 0;
my @exp_per_process_results = ();

@output = `cat $exp_file`;

foreach my $line (@output) {
    chomp($line);

    if( $line =~ /# /i ) {
        if( $line =~ /waiting time/i ) {
            $line =~ /\d+\.\d+/;
            $exp_waiting_time = $&;
        }
        elsif( $line =~ /turnaround time/i ) {
            $line =~ /\d+\.\d+/;
            $exp_turnaround_time = $&;
        }
        elsif( $line =~ /\d/ ) {
            $line =~ s/#\s+//;
            push(@exp_per_process_results, $line);
        }
    }
}

###########################################
# Check the values against expected
###########################################
my $total_errors = 0;

if( $avg_waiting_time != $exp_waiting_time ) {
    printf("Error: Waiting time expected to be (%6.2f) but actual was (%6.2f)!\n",
           $exp_waiting_time, $avg_waiting_time);
    ++$total_errors;
}

if( $avg_turnaround_time != $exp_turnaround_time ) {
    printf("Error: Turnaround time expected to be (%6.2f) but actual was (%6.2f)!\n",
           $exp_turnaround_time, $avg_turnaround_time);
    ++$total_errors;
}

foreach my $pr (@per_process_results) {
    if( 0 != compare_per_process($pr) ) {
        ++$total_errors;
    }
}


###########################################
# Determine pass/fail
###########################################
display_result($total_errors);

#exit $total_errors;
exit 0;

#
# Display the result of the test
#
sub display_result() {
    my $num_errors = shift(@_);

    if( 0 == $num_errors ) {
        print "Passed!\n";
    }
    else {
        print "*"x5 . " Failed 1 test! " . "*"x5 . "\n";
    }

    return $num_errors;
}

#
# Given an 'actual' per process line, find the corresponding 'expected' line
# and compare the two results.
#
sub compare_per_process() {
    my $orig = shift(@_);
    my @values = split(/\s+/, $orig);
    my @exp_values = ();
    my $was_found = 0;

    #
    # Find the match for this process in the expected set
    #
    foreach my $exp_orig (@exp_per_process_results) {
        @exp_values = split(/\s+/, $exp_orig);

        if( $exp_values[0] == $values[0] ) {
            $was_found = 1;

            #
            # Make sure all values are present
            #
            if( scalar(@exp_values) != scalar(@values) ) {
                printf("Error: Per process line does not contain exactly five numbers\n");
                printf("       Expected: %s\n", $exp_orig);
                printf("       Actual  : %s\n", $orig);
                return -99;
            }

            #
            # Check all of the values
            #
            my $total = 0;
            for(my $i = 0; $i < scalar(@exp_values); ++$i ) {
                if( $exp_values[$i] != $values[$i] ) {
                    printf("Error: Per process line at position %d is incorrect. Expected (%4d), Actual (%4d)\n",
                           ($i+1), $exp_values[$i], $values[$i]);
                    ++$total;
                }
            }

            #
            # If one or more of the values was incorrect display an error.
            #
            if( $total > 0 ) {
                printf("       Expected: %s\n", $exp_orig);
                printf("       Actual  : %s\n", $orig);
                return -1 * $total;
            }

        }
    }

    #
    # If a match was not found then issue an error
    #
    if( 0 == $was_found ) {
        printf("Error: Could not find a match for the following line in the expected output\n");
        printf("       Expected: <no match found>\n");
        printf("       Actual  : %s\n", $orig);
        printf("       Expected Output Trace File: %s\n", $exp_file);
        return -88;
    }

    return 0;
}
