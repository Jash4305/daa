#include <stdlib.h>
#include <stdio.h>

int main() {
    int isRunning = 1, request, headLocation;
    printf("Enter the head location : ");
    scanf("%d", &headLocation);
    printf("Enter -1 to exit \n");
    int i = 1, sum = 0;
    while(isRunning) {
        printf("Request %d : ", i);
        i++;
        scanf("%d", &request);
        if(request != -1) {
            sum += abs(request - headLocation);
            headLocation = request;
        }
        else{
            printf("Total Head Movement : %d", sum);
            isRunning = 0;
        }
    }
    
    return 0;
}