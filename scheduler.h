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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/******************************
 * Defines
 ******************************/


/******************************
 * Structures
 ******************************/


/******************************
 * Global Variables
 ******************************/


/******************************
 * Function declarations
 ******************************/
void first_come_first_serve(int ** process_info, int ** orig_process, int num_process);

void shortest_job_first(int ** process_info, int ** orig_process, int num_process);

void priority(int ** process_info, int ** orig_process, int num_process);

void round_robin(int ** process_info, int num_process, int quantum);

void bubble_sort(int ** process_info, int num_process, int sort_column);

void print_results(int ** process_info, int num_process, double total_wait, double total_turnaround);