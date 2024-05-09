#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 3 

int pageFaults = 0;


bool pageExists(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int findOptimalPage(int pages[], int numPages, int frames[], int numFrames, int startIndex) {
    int farthest = startIndex;
    int farthestIndex = -1;
    for (int i = 0; i < numFrames; i++) {
        int j;
        for (j = startIndex; j < numPages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    farthestIndex = i;
                }
                break;
            }
        }
        if (j == numPages) {
            return i; 

        }
    }
    return farthestIndex; 
}


void optimalPageReplacement(int pages[], int numPages) {
    int frames[MAX_FRAMES];
    int numFrames = 0;

    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> ", pages[i]);
        if (!pageExists(pages[i], frames, numFrames)) {
            if (numFrames < MAX_FRAMES) {
                frames[numFrames++] = pages[i]; 
            } else {
                int replaceIndex = findOptimalPage(pages, numPages, frames, numFrames, i + 1);
                frames[replaceIndex] = pages[i]; 
            }
            pageFaults++;
            // printf("Page Fault\n");
        }
    }
}

int main() {
    int numPages;
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[numPages];
    printf("Enter the sequence of pages: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    optimalPageReplacement(pages, numPages);
    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
