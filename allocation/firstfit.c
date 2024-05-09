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

void firstFit(Process * p, Memory * m, int numProcess, int numMemory) {

    for(int i = 0; i < numProcess; i++) {
        for(int j = 0; j < numMemory; j++) {
            if(p[i].blockId == -1 && p[i].size <= m[j].capacity) {
                if(p[i].size <= m[j].int_frag) {
                    p[i].blockId = m[j].id;
                    m[j].int_frag -= p[i].size;
                    break;
                }
            }
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

    firstFit(p, m, numProcess, numMemory);

    // Process p[4];
    // Memory m[4];

    // p[0].id = 1;
    // p[0].size = 150;
    // p[0].blockId = -1;

    // p[1].id = 2;
    // p[1].size = 300;
    // p[1].blockId = -1;
    
    // p[2].id = 3;
    // p[2].size = 50;
    // p[2].blockId = -1;

    // p[3].id = 4;
    // p[3].size = 50;
    // p[3].blockId = -1;


    // m[0].id = 1;
    // m[0].capacity = 100;
    // m[0].int_frag = m[0].capacity;

    // m[1].id = 2;
    // m[1].capacity = 200;
    // m[1].int_frag = m[1].capacity;
    
    // m[2].id = 3;
    // m[2].capacity = 250;
    // m[2].int_frag = m[2].capacity;

    // m[3].id = 4;
    // m[3].capacity = 300;
    // m[3].int_frag = m[3].capacity;


    // firstFit(p, m, 4, 4);

    return 0;
}