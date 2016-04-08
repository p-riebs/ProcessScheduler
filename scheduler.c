/*
 * Parker Riebs
 * 4/7/2016
 *
 * Mocks a operating system scheduler and takes a list of processes
 * from a file and finds the wait and turn around time for each
 * process. Then, it totals the wait and turn around times and finds the
 * averages of each.
 * Uses techniques:
 * First-Come-First-Serve (FCFS)
 * Shortest Job First (SJF)
 * Priority
 * Round Robin (RR)
 * 
 * This program is a way to find which sheduling algorithm is best for
 * a list of processes.
 *
 * CS 441/541: CPU Scheduler (Project 4)
 */
#include "scheduler.h"

int main(int argc, char **argv) 
{

    FILE * file = NULL;
    char line[256];
    int i;
    int scheduler = 0;
    int quantum = 0;
    char * filename = NULL;
    // Process information that can be sorted in any way.
    int ** process_info;
    // Same process information that will keep inputted process order.
    int ** orig_process;
    int num_process;

    // Process parameters
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0 && argc > i)
        {
            scheduler = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            printf("Need to specify a scheduling algorithm.\n");
            exit(0);
        }
        else if (strcmp(argv[i], "-q") == 0 && argc - 1 > i)
        {
            quantum = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-q") == 0)
        {
            printf("Need to specify a quantum.\n");
            exit(0);
        }
        else
        {
            filename = argv[i];
        }
    }

    // Argument error check.
    if (scheduler == 0 || (scheduler == 4 && quantum == 0) || filename == NULL)
    {
        printf("All the arguments were not specified.\n");
        exit(0);
    }

    // Show argument input to user.
    // Print name of scheduler.
    printf("Scheduler   : %2d ", scheduler);
    if (scheduler == 1)
    {
        printf("FCFS\n");
    }
    else if (scheduler == 2)
    {
        printf("SJF\n");
    }
    else if (scheduler == 3)
    {
        printf("Priority\n");
    }
    else if (scheduler == 4)
    {
        printf("RR\n");
    }
    printf("Quantum     : %2d\n", quantum);
    printf("Sch. File   : %s\n", filename);
    printf("-------------------------------\n");

    // Open the file to be read.
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: unable to open file %s\n", argv[1]);
        return -1;
    }

    // Get first line of file to find number of processes in the file.
    fgets(line, 256, file);
    num_process = atoi(line);

    printf("Arrival Order: ");

    // Process information that can be sorted in any way.
    process_info = malloc(num_process * (sizeof(int *)));
    // Same process information that will keep inputted process order.
    orig_process = malloc(num_process * sizeof(int *));

    // Start getting process information from file.
    fgets(line, 256, file);
    for (i = 0; i < num_process; i++)
    {
        // 5 columns of process information integers.
        process_info[i] = malloc(5 * sizeof(int));
        orig_process[i] = malloc(5 * sizeof(int));

        // Take file inputs and put them into process information arrays.
        process_info[i][0] = atoi(strtok(strdup(line), " "));
        orig_process[i][0] = process_info[i][0];
        process_info[i][1] = atoi(strtok(NULL, " "));
        orig_process[i][1] = process_info[i][1];
        process_info[i][2] = atoi(strtok(NULL, " "));
        orig_process[i][2] = process_info[i][2];

        if (i == 0)
        {
            printf("%3d", process_info[i][0]);
        }
        else
        {
            printf(",%3d", process_info[i][0]);
        }

        fgets(line, 256, file);
    }

    printf("\n");

    // Print process information.
    printf("Process Information:\n");
    for (i = 0; i < num_process; i++)
    {
        printf("%2d %4d %3d\n", process_info[i][0], process_info[i][1], process_info[i][2]);
    }
    printf("-------------------------------\n");
    printf("Running...\n");

    // Find what scheduling algorthim to use based off user input.
    if (scheduler == 1)
    {
        first_come_first_serve(process_info, orig_process, num_process);
    }
    else if (scheduler == 2)
    {
        shortest_job_first(process_info, orig_process, num_process);
    }
    else if (scheduler == 3)
    {
        priority(process_info, orig_process, num_process);
    }
    else if (scheduler == 4)
    {
        round_robin(process_info, num_process, quantum);
    }

    // Clean up used variables.
    for (i = 0; i < num_process; i++)
    {
        free(process_info[i]);
        free(orig_process[i]);
        process_info[i] = NULL;
        orig_process[i] = NULL;
    }

    free(process_info);
    process_info = NULL;
    free(orig_process);
    orig_process = NULL;

    return 0;
}

void first_come_first_serve(int ** process_info, int ** orig_process, int num_process)
{
    // Keep track at what time the cpu is currently at.
    int cpu_counter = 0;
    int i;
    int j;
    // Keep track of the total wait and turn around times for each process.
    double total_wait = 0;
    double total_turnaround = 0;

    for (i = 0; i < num_process; i++)
    {
        // Setting wait time.
        process_info[i][3] = cpu_counter;
        total_wait += cpu_counter;
        cpu_counter += process_info[i][1];
        // Setting turn around time.
        process_info[i][4] = cpu_counter;
        total_turnaround += cpu_counter;
    }

    // Copy newly found wait and turn around times to original process order
    // for printf purposes.
    for (i = 0; i < num_process; i++)
    {
        for (j = 0; j < num_process; j++)
        {
            if (process_info[i][0] == orig_process[j][0])
            {
                orig_process[j][3] = process_info[i][3];
                orig_process[j][4] = process_info[i][4];
            }
        }
    }

    // Print information about process scheduling.
    print_results(orig_process, num_process, total_wait, total_turnaround);
}

void shortest_job_first(int ** process_info, int ** orig_process, int num_process)
{
    // Sort the process information by it's CPU time column.
    bubble_sort(process_info, num_process, 1);
    // Process information is now sorted by CPU time from first to last, use
    // first come first serve to finish.
    first_come_first_serve(process_info, orig_process, num_process);
}

void priority(int ** process_info, int ** orig_process, int num_process)
{
    // Sort the process information by it's Priority column.
    bubble_sort(process_info, num_process, 2);
    // Process information is now sorted from first to last, use
    // first come first serve to finish.
    first_come_first_serve(process_info, orig_process, num_process);
}

void round_robin(int ** process_info, int num_process, int quantum)
{
    // Keep track of the remaining CPU time for each process.
    int * progress = malloc(sizeof(int) * num_process);
    int i;
    int uncompleted_process = num_process;
    int cpu_counter = 0;
    double total_wait = 0;
    double total_turnaround = 0;

    // Copy all cpu times to progress tracker.
    for (i = 0; i < num_process; i++)
    {
        progress[i] = process_info[i][1];
    }

    while (uncompleted_process > 0)
    {
        for (i = 0; i < num_process; i++)
        {
            if (progress[i] == 0)
            {
                // Skip, process is finished.
            }
            else if (progress[i] - quantum < 1)
            {
                // Process is finishing in this segment.
                process_info[i][3] = cpu_counter - process_info[i][3] * quantum;
                total_wait += process_info[i][3];
                cpu_counter += progress[i];
                process_info[i][4] = cpu_counter;
                total_turnaround += process_info[i][4];
                progress[i] = 0;
                uncompleted_process--;
            }
            else
            {
                // Process is not completed yet.
                cpu_counter += quantum;
                progress[i] -= quantum;
                process_info[i][3]++;
            }
        }
    }

    // Print found information.
    print_results(process_info, num_process, total_wait, total_turnaround);

    // Clean up
    free(progress);
    progress = NULL;
}

void bubble_sort(int ** process_info, int num_process, int sort_column)
{
    int i;
    int j;
    int * swap = malloc(5 * sizeof(int));

    for (i = 0; i < num_process; i++)
    {
        for (j = 0; j < num_process - 1; j++)
        {
            if (process_info[j][sort_column] > process_info[j + 1][sort_column])
            {
                // Swap malloc arrays with memcpy
                memcpy(swap, process_info[j + 1], 5 * sizeof(int));
                memcpy(process_info[j + 1], process_info[j], 5 * sizeof(int));
                memcpy(process_info[j], swap, 5 * sizeof(int));
            }
        }
    }

    // Clean up.
    free(swap);
    swap = NULL;
}

void print_results(int ** process_info, int num_process, double total_wait, double total_turnaround)
{
    int i;
    // Find averages of wait and turn around times.
    double avg_wait = total_wait / num_process;
    double avg_turnaround = total_turnaround / num_process;

    // Print each processes information.
    printf("##################################################\n");
    printf("#  #    CPU    Pri      W      T\n");

    for (i = 0; i < num_process; i++)
    {
        printf("#%3d %6d %6d %6d %6d\n", process_info[i][0], process_info[i][1], process_info[i][2], process_info[i][3], process_info[i][4]);
    }
    // Print the averages.
    printf("##################################################\n");
    printf("# Avg. Waiting Time   : %6.2f\n", avg_wait);
    printf("# Avg. Turnaround Time: %6.2f\n", avg_turnaround);
    printf("##################################################\n");

}