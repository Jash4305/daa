#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int pid, at, bt, ct, wt, trt, completed, in_queue;
}Process;

typedef struct Queue{
    int size, front, rear;
    Process *array;
}Queue;

int isFull(Queue * q) {
    if(q->rear == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(Queue * q) {
    if(q->front == -1 && q->rear == -1)
        return 1;
    return 0;
}

void push(Queue * q, Process *element) {
    if(isEmpty(q))
    {
        q->front=0;
        q->rear=0;
    }
    else
    {
        q->rear++;
    }
    q->array[q->rear] = *element;
    element->in_queue = 1;
}

Process pop(Queue *q) {
    if (isEmpty(q)) {
        return;
    }
    else
    {
        Process poppedProcess = (q->array[q->front]);
        if(q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
        poppedProcess.in_queue = 0;
        return poppedProcess;
    }
}

void print(Process *p, int size) {
    printf("ID \tAT \tBT \tCT \tTRT \tWT\n");
    for (int i = 0; i < size; i++)
        printf("P%d \t%d \t%d \t%d \t%d \t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].trt, p[i].wt);
}

// sorting based on arrival time
void bubbleSort(Process * p, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void bubbleSortBT(Queue *q) {
    int n = q->rear - q->front + 1; // Calculate the number of elements in the queue
    for (int i = q->front; i <= q->rear; i++) {
        for (int j = q->front; j <= q->rear-1; j++) {
            if (q->array[j].bt > q->array[j + 1].bt) {
                Process temp = q->array[j];
                q->array[j] = q->array[j + 1];
                q->array[j + 1] = temp;
            }
        }
    }
}

void update_through_currentProcess(Process *p, int n, Process currentProcess, int currentTime)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i].pid == currentProcess.pid)
            break;
    }
    p[i].ct = currentTime + p[i].bt;
    p[i].trt = p[i].ct - p[i].at;
    p[i].wt = p[i].trt - p[i].bt;
    p[i].completed=1;
}

void sjfScheduling(Process *p, int size, Queue *q)
{
    int completed = 0;
    int currentTime = 0;
    bubbleSort(p, size); // Sort processes based on arrival time

    currentTime = p[0].at;
    int iteration=0;

    while (completed < size)
    {
        iteration++;
        int count = 0;
        // Add processes to the queue where arrival time <= current time
        for (int i = 0; i < size; i++)
        {
            if (p[i].at <= currentTime && p[i].in_queue == 0 && p[i].completed==0) {
                push(q, &p[i]);
                count++;
            }
        }  
        if(isEmpty(q))
        {
            currentTime++;
        }
        else
        {
            bubbleSortBT(q);
            Process currentProcess = pop(q);
            int i;
            for(i=0;i<size;i++)
            {
                if(p[i].pid == currentProcess.pid)
                    break;
            }
            p[i].in_queue = 0;
            p[i].ct = currentTime + p[i].bt;
            p[i].trt = p[i].ct - p[i].at;
            p[i].wt = p[i].trt - p[i].bt;
            currentTime = p[i].ct;
            p[i].completed=1;
            completed++;
        }
    }
    print(p, size);
}

int main() {
    Queue q;
    q.size = 10;
    q.front = -1; 
    q.rear = -1;
    q.array = (Process *)calloc(q.size, sizeof(Process));

    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    Process *p = (Process*)calloc(num_processes, sizeof(Process));
    
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the process %d id: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter the process %d arrival time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the process %d burst time: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].completed = 0;
        printf("\n");
    }
    sjfScheduling(p, num_processes, &q);

    // p[0].pid=1;
    // p[0].at=6;
    // p[0].bt=2;
    // p[0].completed=0;
    // p[0].in_queue=0;
    
    // p[1].pid=2;
    // p[1].at=5;
    // p[1].bt=2;
    // p[1].completed=0;
    // p[1].in_queue=0;
    
    // p[2].pid=3;
    // p[2].at=1;
    // p[2].bt=8;
    // p[2].completed=0;
    // p[2].in_queue=0;
    
    // p[3].pid=4;
    // p[3].at=0;
    // p[3].bt=3;
    // p[3].completed=0;
    // p[3].in_queue=0;
    
    // p[4].pid=5;
    // p[4].at=4;
    // p[4].bt=4;
    // p[4].completed=0;
    // p[4].in_queue=0;

    // sjfScheduling(p, 5, &q);
    
    return 0;
}