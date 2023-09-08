#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a process
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate average waiting time and turnaround time
void calculateAverageTimes(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
}

// Round Robin scheduling algorithm
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            struct Process *p = &processes[i];

            if (p->remaining_time > 0) {
                int execute_time = (p->remaining_time < time_quantum) ? p->remaining_time : time_quantum;

                // Simulate CPU burst time (generating randomly)
                int random_burst = rand() % 10 + 1;
                execute_time = (execute_time < random_burst) ? execute_time : random_burst;

                // Update remaining time
                p->remaining_time -= execute_time;

                // Update waiting time for other processes
                for (int j = 0; j < n; j++) {
                    if (j != i && processes[j].arrival_time <= current_time) {
                        processes[j].waiting_time += execute_time;
                    }
                }

                // Update current time
                current_time += execute_time;

                // Update turnaround time if the process is completed
                if (p->remaining_time == 0) {
                    remaining_processes--;
                    p->turnaround_time = current_time - p->arrival_time;
                }
                printf("P%d (%d-%d) | ", p->id, current_time - execute_time, current_time);
            }
        }
    }
}

int main() {
    int n, time_quantum;
    srand(time(NULL));

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nGantt Chart:\n");
    roundRobin(processes, n, time_quantum);

    printf("\n\nProcess\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].id, processes[i].turnaround_time, processes[i].waiting_time);
    }

    calculateAverageTimes(processes, n);

    return 0;
}

