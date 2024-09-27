#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
bool isSafeState(int need[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int numProcesses, int numResources) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int count = 0;
    for (int i = 0; i < numResources; i++) work[i] = available[i];

    while (count < numProcesses) {
        bool found = false;
        for (int p = 0; p < numProcesses; p++) {
                int j;
                for (j = 0; j < numResources; j++) {
                    if (need[p][j] > work[j]) break;
                }
                if (j == numResources) {
                    for (int k = 0; k < numResources; k++) work[k] += allocation[p][k];
                    safeSequence[count++] = p;
            if (!finish[p]) {
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) return false;
    }

    printf("Safe sequence: ");
    for (int i = 0; i < numProcesses; i++) printf("P%d ", safeSequence[i]);
    printf("\n");
    return true;
}

int main() {
    int numProcesses, numResources;
    int available[MAX_RESOURCES], maximum[MAX_PROCESSES][MAX_RESOURCES], allocation[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES];

    printf("Processes: "); scanf("%d", &numProcesses);
    printf("Resources: "); scanf("%d", &numResources);

    printf("Available resources:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    printf("Maximum matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i + 1);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i + 1);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    if (!isSafeState(need, allocation, available, numProcesses, numResources)) {
        printf("System is in an unsafe state!\n");
    } else {
        printf("System is in a safe state!\n");
    }

    return 0;
}
