#include <stdlib.h>
#include <stdio.h>

typedef struct Process {
    int id, size, blockId;
} Process;

typedef struct Memory {
    int id, capacity, int_frag;
} Memory;

void print(Process *p, int numProcess) {
    printf("Process Id\tProcess Size\tAllocated Block\n");
    for (int i = 0; i < numProcess; i++) {
        printf("%8d\t%8d\t", p[i].id, p[i].size);
        if (p[i].blockId == -1)
            printf("Not Allocated\n");
        else
            printf("%8d\n", p[i].blockId);
    }
}

int findNextRequest(Memory *m, int numMemory, int lastBlock, int processSize) {
    int nextBlock = -1;
    for (int i = lastBlock; i < numMemory; i++) {
        if (m[i].capacity >= processSize) {
            nextBlock = i;
            break;
        }
    }
    if (nextBlock == -1) {
        for (int i = 0; i < lastBlock; i++) {
            if (m[i].capacity >= processSize) {
                nextBlock = i;
                break;
            }
        }
    }
    return nextBlock;
}

void nextFit(Process *p, Memory *m, int numProcess, int numMemory) {
    int lastBlock = 0;
    for (int i = 0; i < numProcess; i++) {
        int nextBlock = findNextRequest(m, numMemory, lastBlock, p[i].size);
        if (nextBlock != -1) {
            p[i].blockId = m[nextBlock].id;
            m[nextBlock].int_frag -= p[i].size;
            lastBlock = nextBlock;
        }
    }
    print(p, numProcess);
}

int main() {
    int numProcess, numMemory;
    printf("Enter the number of processes : ");
    scanf("%d", &numProcess);
    printf("Enter the number of memory blocks : ");
    scanf("%d", &numMemory);
    printf("\n");

    Process p[numProcess];
    Memory m[numMemory];

    printf("\nInput Memory block ID and capacity..\n");
    for (int i = 0; i < numMemory; i++) {
        printf("ID for Memory Block %d : ", i + 1);
        scanf("%d", &m[i].id);
        printf("Capacity for Memory Block %d : ", i + 1);
        scanf("%d", &m[i].capacity);
        m[i].int_frag = m[i].capacity;
        printf("\n");
    }

    printf("Input Process ID and size..\n");
    for (int i = 0; i < numProcess; i++) {
        printf("ID for Process %d : ", i + 1);
        scanf("%d", &p[i].id);
        printf("Size for Process %d : ", i + 1);
        scanf("%d", &p[i].size);
        p[i].blockId = -1;
        printf("\n");
    }

    nextFit(p, m, numProcess, numMemory);

    return 0;
}
