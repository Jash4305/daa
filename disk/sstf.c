#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Request {
    int reqCylinder;
    bool isServed;
}Request;

int findNextRequest(int requestArray[], int totalRequest, int headPosition) {
    int mindifference = INT_MAX;
    int minIndex = 0;
    int difference = 0;
    for(int i = 0; i < totalRequest; i++) {
        difference = abs(headPosition - requestArray[i]);
        if(difference < mindifference) {
            mindifference = difference;
            minIndex = i;
        }
    }
    return minIndex;

}

void sstf(int requestArray[], int totalRequest, int headPosition) {
    int nextRequestIndex;
    int servedRequests = 0;
    int sum = 0;
    while(servedRequests < totalRequest) {
        nextRequestIndex = findNextRequest(requestArray, totalRequest, headPosition);
        printf("%d ", nextRequestIndex);
        sum += abs(headPosition - requestArray[nextRequestIndex]);
        headPosition = requestArray[nextRequestIndex];
        servedRequests++;
    }
    printf("\nTotal Head Movement is %d", sum);
    
}

int main() {
    
    // int cylinderSize, totalRequest, request, headPosition;
    // printf("Enter the cylinder Size : ");
    // scanf("%d", &cylinderSize);
    // printf("Enter the head position : ");
    // scanf("%d", &headPosition);
    // printf("Enter the total number of requests : ");
    // scanf("%d", &totalRequest);

    // int requestArray[totalRequest];

    Request r[7];

    r[0].isServed = false;
    r[0].reqCylinder = 82;

    r[1].isServed = false;
    r[1].reqCylinder = 170;

    r[2].isServed = false;
    r[2].reqCylinder = 43;

    r[3].isServed = false;
    r[3].reqCylinder = 140;

    r[4].isServed = false;
    r[4].reqCylinder = 24;

    r[5].isServed = false;
    r[5].reqCylinder = 16;

    r[6].isServed = false;
    r[6].reqCylinder = 190;    
    // sstf(requestArray1, 7, 50);

    return 0;
}