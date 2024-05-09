#include <stdlib.h>
#include <stdio.h>

int findPage(int arr[], int noOfFrames, int page) {
    for(int i = 0; i < noOfFrames; i++) {
        if(arr[i] == page)
            return 1;
    }
    return 0;
}

int fifo(int arr[], int numPages, int noOfFrames) {
    int pages[noOfFrames];
    int nextIndex = 0;
    int pageFaults = 0;
    for(int i = 0; i < noOfFrames; i++)
        pages[i] = -1;
    
    for (int i = 0; i < numPages; i++) {
        int page = arr[i];

        if (!findPage(pages, noOfFrames, page)) {
            pages[nextIndex] = page;
            nextIndex = (nextIndex + 1) % noOfFrames;
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int arr[] = {1,3,0,3,5,6,3};
    int n = sizeof(arr)/sizeof(int);
    int noOfFrames = 3;
    printf("Number of Pages is %d\nFrame Size is %d\n", n, noOfFrames);

    int pageFaults = fifo(arr, n, noOfFrames);
    int pageHits = n - pageFaults;
    printf("Page Faults : %d\n", pageFaults);
    printf("Page Hits : %d", pageHits);

    return 0;
}