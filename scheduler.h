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
 /*
 *  Runs and prints First-Come-First-Serve scheduling algorithm with process 
 *  information.
 *
 *  Parameters:
 *   process_info: The 2d array of process information that can be sorted.
 *   orig_process: The 2d array of process information that preserves process
 *                 order
 *   num_process: Number of processes in process_info and orig_process.
 */
void first_come_first_serve(int ** process_info, int ** orig_process, int num_process);

/*
*  Runs and prints Shortest Job First scheduling algorithm with process
*  information.
*
*  Parameters:
*   process_info: The 2d array of process information that can be sorted.
*   orig_process: The 2d array of process information that preserves process
*                 order
*   num_process: Number of processes in process_info and orig_process.
*/
void shortest_job_first(int ** process_info, int ** orig_process, int num_process);

/*
*  Runs and prints Priority scheduling algorithm with process
*  information.
*
*  Parameters:
*   process_info: The 2d array of process information that can be sorted.
*   orig_process: The 2d array of process information that preserves process
*                 order
*   num_process: Number of processes in process_info and orig_process.
*/
void priority(int ** process_info, int ** orig_process, int num_process);

/*
*  Runs and prints Round Robin scheduling algorithm with process
*  information.
*
*  Parameters:
*   process_info: The 2d array of process information that can be sorted.
*   num_process: Number of processes in process_info and orig_process.
*   quantum: The amount of time for each process cycle.
*/
void round_robin(int ** process_info, int num_process, int quantum);

/*
*  Sorts a 2d array of process information with bubble sort.
*
*  Parameters:
*   process_info: The 2d array of process information that can be sorted.
*   num_process: Number of processes in process_info and orig_process.
*   sort_column: The column of the process information in which to sort.
*/
void bubble_sort(int ** process_info, int num_process, int sort_column);

/*
*  Prints all process information and extra scheduling algorithm data.
*
*  Parameters:
*   process_info: The 2d array of process information that can be sorted.
*   num_process: Number of processes in process_info and orig_process.
*   total_wait: The total amount of time waited by each process.
*   total_turnaround: The total amount of time it took for each process to
*                     turnaround.
*/
void print_results(int ** process_info, int num_process, double total_wait, double total_turnaround);