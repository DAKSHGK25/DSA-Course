#include <stdio.h>

int * ascending(int arr[10], int n) {
    for (int i=0; i<10; i++) {
        for (int j=i+1; j<10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int * descending(int arr[10], int n) {
    for (int i=0; i<10; i++) {
        for (int j=i+1; j<10; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return &arr[0];
}

int main() {
    int arr[10] = {65, 55, 86, 11, 66, 22, 1, 91, 7, 19};
    printf("Unsorted Array: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    int *ptr1 = ascending(arr, 10);
    printf("Array sorted in Ascending order: ");
    for (int i=0; i<10; i++) {
        printf("%d ", *ptr1);
        ptr1++;
    }

    printf("\n");
    int *ptr2 = descending(arr, 10);
    printf("Array sorted in Descending order: ");
    for (int i=0; i<10; i++) {
        printf("%d ", *ptr2);
        ptr2++;
    }

    return 0;
}