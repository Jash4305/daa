#include <stdlib.h>
#include <stdio.h>

typedef struct Process
{
    int pid, at, bt, ct, wt, trt;
}Process;

void print(Process *p, int size) {
    printf("ID \tAT \tBT \tCT \tTRT \tWT\n");
    for (int i = 0; i < size; i++)
        printf("P%d \t%d \t%d \t%d \t%d \t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].trt, p[i].wt);
}

void bubbleSort(Process * p, int size) {
    Process temp;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(p[j].at > p[j+1].at){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void ganttChart(Process * p, int n) {
    for(int i = 0; i < n; i++) 
        printf("----------------");
    printf("\n");

    for(int i = 0; i < n; i++)
        printf("|\tP%d\t", p[i].pid);
    printf("|\n");
    
    for(int i = 0; i < n; i++) 
        printf("----------------");
    printf("\n");
    
    printf("0 \t\t");
    for(int i = 0; i < n; i++)
        printf("%d \t\t", p[i].ct);
}

double avgWaitTime(Process * p, int n) {
    double sum = 0;
    for(int i = 0; i < n; i ++)
        sum += p[i].wt;
    return (sum/n);
}

double avgTrtTime(Process * p, int n) {
    double sum = 0;
    for(int i = 0; i < n; i ++)
        sum += p[i].trt;
    return (sum/n);
}

void fcfsScheduling(Process * p, int num_processes) {
    bubbleSort(p, num_processes);
    int currentTime = p[0].at;
    for(int i = 0; i < num_processes; i++) {
        if(currentTime >= p[i].at){
            p[i].ct = currentTime + p[i].bt; 
            p[i].trt = p[i].ct - p[i].at;    
            p[i].wt = p[i].trt - p[i].bt;    
            currentTime = p[i].ct;           
        } else {
            currentTime = p[i].at + p[i].bt; // Jump to process arrival time
            p[i].ct = currentTime;           
            p[i].trt = p[i].ct - p[i].at;    
            p[i].wt = p[i].trt - p[i].bt;    
        }
    }
    print(p, num_processes);
    printf("\nAverage wait time : %.2f\n", avgWaitTime(p, num_processes));
    printf("Average turn around time : %.2f\n", avgTrtTime(p, num_processes));
    printf("\nGantt Chart :\n");
    ganttChart(p, num_processes);
}


int main() {

    int num_processes;
    printf("Enter the number of proceses : ");
    scanf("%d", &num_processes);
    
    Process p[num_processes];
    
    // inputs
    for(int i = 0; i < num_processes; i++) {
        printf("Enter the process %d id : ", i+1);
        scanf("%d", &p[i].pid);
        printf("Enter the process %d arrival time : ", i+1);
        scanf("%d", &p[i].at);
        printf("Enter the process %d burst time : ", i+1);
        scanf("%d", &p[i].bt);
        printf("\n");
    }
    
    fcfsScheduling(p, num_processes);
    return 0;
}