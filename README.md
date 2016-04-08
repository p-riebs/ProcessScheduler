# CS441/541 Project 4

## Author(s):

Parker Riebs


## Date:

4/7/2016

## Description:

Mocks a operating system scheduler and takes a list of processes
from a file and finds the wait and turn around time for each
process. Then, it totals the wait and turn around times and finds the
averages of each.
Uses techniques:
First-Come-First-Serve (FCFS)
Shortest Job First (SJF)
Priority
Round Robin (RR)

This program is a way to find which sheduling algorithm is best for
a list of processes.

## How to build the software

Run "make" while in the scheduler.c directory.

## How to use the software

Specify the "-s" which is the type of scheduling algorithm to use.
-s 1 : (First-Come, First-Served (FCFS))
-s 2 : (Shortest-Job First (SJF))
-s 3 : (Priority)
-s 4 : (Round-Robin (RR))

-q
The quantum to use in the Round-Robin scheduling algorithm. This option is 
not required for the other scheduling algorithms, and, if provided for those 
algorithms, is ignored.

A filename is also required, which holds process information.

An example of a full command:
$ ./scheduler -s 4 -q 10 given-tests/level7.txt

## How the software was tested

A "make check" was performed and passed all tests. Extra tests were also 
added and worked as expected. The thought process of how each algorithm works
makes sense to me.

## Test Suite

test1.txt - Tests out of order processes.
test2.txt - Tests regular processes combined with a process with a very 
			high priority.
test3.txt - Tests regular processes combined with a process with a very 
			high order.
test4.txt - Tests processses with many very high orders.

These files are located in "tests/" and can be run like any other process
information file.
Example: 
$ ./scheduler -s 2 tests/test1.txt

## Known bugs and problem areas

None that I know of.
