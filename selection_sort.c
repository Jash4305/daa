#include <stdlib.h>
#include <stdio.h>

void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
    
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
    
    for (int k = 0; k < size; k++) {
        printf("%d ", a[k]);
    }
}

int main() {
    int numElements;
    printf("Enter the number of elements : ");
    scanf("%d", &numElements);

    int array[numElements];

    for (int i = 0; i < numElements; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    selectionSort(array, numElements);

    return 0;
}
