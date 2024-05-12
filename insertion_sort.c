#include <stdlib.h>
#include <stdio.h>


void insertionSort(int a[], int size) {
    int key=0, j = 0;
    for(int i = 1; i < size; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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

    for(int i = 0; i < numElements; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    insertionSort(array, numElements);

    return 0;
}