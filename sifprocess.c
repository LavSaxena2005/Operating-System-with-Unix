#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;        // Process ID
    int burst;     // Burst time
    int waiting;   // Waiting time
    int turnaround;// Turnaround time
    int completion;// Completion time
} Process;

// Function to calculate waiting time and turnaround time
void calculateTimes(Process processes[], int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i].completion = currentTime + processes[i].burst;
        processes[i].turnaround = processes[i].completion; // Since arrival time is 0
        processes[i].waiting = processes[i].turnaround - processes[i].burst;
        
        currentTime = processes[i].completion;
        
        totalWaitingTime += processes[i].waiting;
        totalTurnaroundTime += processes[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

// Function to implement SJF Scheduling
void sjfScheduling(Process processes[], int n) {
    // Sort processes by burst time (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burst < processes[i].burst) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate times after sorting
    calculateTimes(processes, n);

    // Print process details
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].burst,
               processes[i].waiting,
               processes[i].turnaround,
               processes[i].completion);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    // Get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Get burst times for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burst);
    }

    // Call SJF Scheduling
    sjfScheduling(processes, n);

    return 0;
}
