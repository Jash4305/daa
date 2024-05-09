
#include <stdlib.h>
#include <stdio.h>

typedef struct PageTable{
    int frame_no, validBit, time;
}PageTable;

int findVacantIndexInPages(int pages[], int framesSize) {
    for(int i = 0; i < framesSize; i++) {
        if(pages[i] == -1)
            return i;
    }
    return -1;
}

int findVictimPageIndex(PageTable * p, int pageReference[], int pages[], int frameSize) {
    int minTime = INT_MAX;
    int minTimeIndex;
    for(int i = 0; i < frameSize; i++) {
        if(p[pages[i]].time < minTime) {
            minTime = p[pages[i]].time;
            minTimeIndex = i;
        }
    }
    return minTimeIndex;
}

int lru(PageTable * p,int pageReference[], int totalPages, int framesSize) {
    int pages[framesSize];
    int pageFault = 0;
    int frameIndex = -1;

    for(int i = 0; i < framesSize; i++)
        pages[i] = -1;

    for(int i = 0; i < totalPages; i++) {
        // page is not present then go in if 
        if(p[pageReference[i]].frame_no == -1 && p[pageReference[i]].validBit == 0) {
            pageFault++;
            frameIndex = findVacantIndexInPages(pages, framesSize);
            if(frameIndex != -1) {
                pages[frameIndex] = pageReference[i];
                p[pageReference[i]].frame_no = frameIndex;
                p[pageReference[i]].validBit = 1;
                p[pageReference[i]].time = i;
            }
            else {
                int victimFrameIndex = findVictimPageIndex(p, pageReference, pages, framesSize);
                p[pages[victimFrameIndex]].validBit = 0;
                p[pages[victimFrameIndex]].frame_no = -1;
                
                p[pageReference[i]].frame_no = victimFrameIndex;
                p[pageReference[i]].validBit = 1;
                p[pageReference[i]].time = i;
            }
        }
    }
    return pageFault;
}

int main() {
    
    // int page_reference[] = {1,3,0,3,5,6,3};
    int totalPages, frameSize, inputPage;
    printf("Enter the total number of pages : ");
    scanf("%d", &totalPages);
    int pageReference[totalPages];
    printf("Enter the frame size : ");
    scanf("%d", &frameSize);

    PageTable p[10];

    printf("\nTaking Page reference string....\n");
    for(int i = 0; i < totalPages; i++) {
        printf("Page reference %d : ", i + 1);
        scanf("%d", &inputPage);
        
        pageReference[i] = inputPage;
        p[inputPage].frame_no = -1;
        p[inputPage].time = -1;
        p[inputPage].validBit = 0;
    }

    int pageFaults = lru(p, pageReference, totalPages, frameSize);
    int pageHits = totalPages - pageFaults;
    printf("\nPage Faults : %d\n", pageFaults);
    printf("Page Hits : %d", pageHits);

    return 0;
}