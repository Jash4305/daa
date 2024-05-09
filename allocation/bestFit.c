#include <stdlib.h>
#include <stdio.h>

typedef struct Process
{
    int id, size, blockId;
}Process;

typedef struct Memory
{
    int id, capacity, int_frag;
}Memory;

void print(Process *p, int numProcess) {
    printf("Process Id\tProcess Size\tAllocated Block\n");
    for(int i = 0; i < numProcess; i++) {
        printf("%8d\t%8d\t", p[i].id, p[i].size);
        if(p[i].blockId == -1)
            printf("Not Allocated\n");
        else
            printf("%8d\n", p[i].blockId);
    }
}

int findWorstBlockId(Memory * m, int numMemory, Process * p) {
    int minIntFrag = INT_MAX;
    int bestBlockId = -1;
    int fragmentation = 0;
    for(int i = 0; i < numMemory; i++) {
        if(p->blockId == -1 && p->size <= m[i].capacity && p->size <= m[i].int_frag) {
            fragmentation = m[i].int_frag - p->size;
            if(fragmentation < minIntFrag) {
                minIntFrag = fragmentation;
                bestBlockId = m[i].id;
            }
        }
    }
    return bestBlockId;
}

void bestFit(Process * p, Memory * m, int numProcess, int numMemory) {
    for(int i = 0; i < numProcess; i++) {
            int bestBlockId = -1;
            if(p[i].blockId == -1) {
                bestBlockId = findWorstBlockId(m, numMemory, &p[i]);
                p[i].blockId = bestBlockId;
                m[bestBlockId - 1].int_frag -= p[i].size;
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

    Process p[numProcess];
    Memory m[numMemory];

    printf("\nInput Memory block ID and capacity..\n");
    for(int i = 0; i < numMemory; i ++) {
        printf("ID for Memory Block %d : ", i + 1);
        scanf("%d", &m[i].id);
        printf("Capacity for Memory Block %d : ", i + 1);
        scanf("%d", &m[i].capacity);
        m[i].int_frag = m[i].capacity;
        printf("\n");
    }

    printf("Input Process ID and size..\n");
    for(int i = 0; i < numProcess; i ++) {
        printf("ID for Process %d : ", i + 1);
        scanf("%d", &p[i].id);
        printf("Size for Process %d : ", i + 1);
        scanf("%d", &p[i].size);
        p[i].blockId = -1;
        printf("\n");
    }

    bestFit(p, m, numProcess, numMemory);

    
    // Process p[4];
    // Memory m[4];

    // p[0].id = 1;
    // p[0].size = 150;
    // p[0].blockId = -1;

    // p[1].id = 2;
    // p[1].size = 300;
    // p[1].blockId = -1;
    
    // p[2].id = 3;
    // p[2].size = 250;
    // p[2].blockId = -1;

    // p[3].id = 4;
    // p[3].size = 100;
    // p[3].blockId = -1;


    // m[0].id = 1;
    // m[0].capacity = 250;
    // m[0].int_frag = m[0].capacity;

    // m[1].id = 2;
    // m[1].capacity = 550;
    // m[1].int_frag = m[1].capacity;
    
    // m[2].id = 3;
    // m[2].capacity = 150;
    // m[2].int_frag = m[2].capacity;

    // m[3].id = 4;
    // m[3].capacity = 200;
    // m[3].int_frag = m[3].capacity;

    // bestFit(p, m, 4, 4);

    return 0;
}