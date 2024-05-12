#include <stdlib.h>
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int searchElement) {
    int mid = (low + high) / 2;

    if(arr[mid] == searchElement)
        return mid;
    else if(searchElement > arr[mid] && mid > 0)
        binarySearch(arr, mid + 1, high, searchElement); // call on right part
    else if(searchElement < arr[mid] && mid > 0)
        binarySearch(arr, low, mid - 1, searchElement); // call on left part
    else
        return -1;
}

int main() {
    
    int numElements, searchElement;
    printf("Enter the number of elements in sorted manner : ");
    scanf("%d", &numElements);

    int array[numElements];

    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Search Element : ");
    scanf("%d", &searchElement);

    int resultIndex = binarySearch(array, 0, numElements - 1, searchElement);
    if(resultIndex != -1)
        printf("Element %d found at index %d", array[resultIndex], resultIndex);
    else
        printf("Element %d not found !", searchElement);
    return 0;
}