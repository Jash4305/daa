#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct Process
{
    int max[MAX], allocation[MAX], need[MAX], id, isCompleted;
}Process;

void print(Process *p, int numProcess, int numResource) {
    printf("Process Id\tMaximum Need\tAllocation\tNeed\n");
    for(int i = 0; i < numProcess; i++) {
        printf("%d\t\t", p[i].id);
        for(int j = 0; j < numResource; j++)
            printf("%d ", p[i].max[j]);
        printf("\t\t");

        for(int j = 0; j < numResource; j++)
            printf("%d ", p[i].allocation[j]);
        printf("\t\t");

        for(int j = 0; j < numResource; j++)
            printf("%d ", p[i].need[j]);
        printf("\n");
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int isSafe(Process * p, int numProcess, int numResources, int available[], int safeSequence[]) {
    int completed = 0;
    int changeFlag = 0;

    while(completed < numProcess) {
        changeFlag = 0;
        for(int i = 0; i < numProcess; i++) {
            int isExecutable = 0;
            // process must be incomplete
            if(p[i].isCompleted != 1) {

                for(int j = 0; j < numResources; j++) {
                    if(p[i].need[j] > available[j]) {
                        isExecutable = 0;
                        break;
                    }
                    else{
                        isExecutable = 1;
                        continue;
                    }
                }

                if(isExecutable == 1) {
                    for(int k = 0; k < numResources; k++) {
                        available[k] += p[i].allocation[k];
                        // changeFlag = 1;
                    }
                    safeSequence[completed] = p[i].id;
                    // printf("%d ,i values if %d\n",p[i].id, completed);
                    p[i].isCompleted = 1;
                    completed++;
                    changeFlag = 1;
                }
            }
        }
        if(changeFlag == 0) {
            break;
        }
    }
    if(changeFlag == 1)
        return 1;
    else
        return 0;
}

void bankerAlgo(Process * p, int numProcess, int numResource, int available[]) {
    int safeSequence[numProcess];
    for(int i = 0; i < numProcess; i++)
        safeSequence[i] = 0;

    printf("Available Resources : ");
    printArray(available, numResource);
    print(p, numProcess, numResource);
    int safety = isSafe(p, numProcess, numResource, available, safeSequence);
    if(safety == 1) {
        printf("\nSystem In Safe state !\n");
        for(int i = 0; i < numProcess; i++) {
            printf("P%d ", safeSequence[i]);
        }
    }
    else    
        printf("\nSystem In unsafe state !\n");
}


int main() {
    
    // int numProcess, numResource;
    // printf("Enter the number of processes : ");
    // scanf("%d", &numProcess);
    // printf("Enter the number of resources : ");
    // scanf("%d", &numResource);
    // printf("\n");
    // Process p[numProcess];
    // for(int i = 0; i < numProcess; i++) {
    //     printf("ID for Process %d : ", i + 1);
    //     scanf("%d", &p[i].id);
    //     for(int j = 0; j < numResource; j++) {
    //         printf("Maximum Resource %d for Process %d : ",j + 1, i + 1);
    //         scanf("%d", &p[i].max[j]);
    //         printf("Allocated Resource %d for Process %d : ",j + 1, i + 1);
    //         scanf("%d", &p[i].allocation[j]);
    //         p[i].need[j] = p[i].max[j] - p[i].allocation[j];
    //     }
    //     printf("\n");
    // }
    // int available[numResource];
    // printf("\n");
    // for(int i = 0; i < numResource; i++) {
    //     printf("Availabilty of Resource %d : ", i + 1);
    //     scanf("%d", &available[i]);
    // }
    // print(p, numProcess, numResource);

    // bankerAlgo(p, numProcess, numResource, available);

    int numProcess = 5, numResource = 3;
    Process p[numProcess];

    p[0].id = 1;
    p[0].max[0] = 7;
    p[0].max[1] = 5;
    p[0].max[2] = 3;
    p[0].allocation[0] = 0;
    p[0].allocation[1] = 1; 
    p[0].allocation[2] = 0;
    p[0].need[0] = p[0].max[0] - p[0].allocation[0];
    p[0].need[1] = p[0].max[1] - p[0].allocation[1];
    p[0].need[2] = p[0].max[2] - p[0].allocation[2];
    p[0].isCompleted = 0;

    p[1].id = 2;
    p[1].max[0] = 3;
    p[1].max[1] = 2;
    p[1].max[2] = 2;
    p[1].allocation[0] = 2;
    p[1].allocation[1] = 0; 
    p[1].allocation[2] = 0;
    p[1].need[0] = p[1].max[0] - p[1].allocation[0];
    p[1].need[1] = p[1].max[1] - p[1].allocation[1];
    p[1].need[2] = p[1].max[2] - p[1].allocation[2];
    p[1].isCompleted = 0;

    p[2].id = 3;
    p[2].max[0] = 9;
    p[2].max[1] = 0;
    p[2].max[2] = 2;
    p[2].allocation[0] = 3;
    p[2].allocation[1] = 0; 
    p[2].allocation[2] = 2;
    p[2].need[0] = p[2].max[0] - p[2].allocation[0];
    p[2].need[1] = p[2].max[1] - p[2].allocation[1];
    p[2].need[2] = p[2].max[2] - p[2].allocation[2];
    p[2].isCompleted = 0;

    p[3].id = 4;
    p[3].max[0] = 2;
    p[3].max[1] = 2;
    p[3].max[2] = 2;
    p[3].allocation[0] = 2;
    p[3].allocation[1] = 1; 
    p[3].allocation[2] = 1;
    p[3].need[0] = p[3].max[0] - p[3].allocation[0];
    p[3].need[1] = p[3].max[1] - p[3].allocation[1];
    p[3].need[2] = p[3].max[2] - p[3].allocation[2];
    p[3].isCompleted = 0;

    p[4].id = 5;
    p[4].max[0] = 4;
    p[4].max[1] = 3;
    p[4].max[2] = 3;
    p[4].allocation[0] = 0;
    p[4].allocation[1] = 0; 
    p[4].allocation[2] = 2;
    p[4].need[0] = p[4].max[0] - p[4].allocation[0];
    p[4].need[1] = p[4].max[1] - p[4].allocation[1];
    p[4].need[2] = p[4].max[2] - p[4].allocation[2];
    p[4].isCompleted = 0;

    int available[] = {3, 3, 2};

    bankerAlgo(p, numProcess, numResource, available);

    return 0;
}