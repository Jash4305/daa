#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int numElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    int array[numElements];

    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, numElements - 1);

    for (int i = 0; i < numElements; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
