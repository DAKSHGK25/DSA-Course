#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int j = i, key = arr[i];
        while(j>0 && key<arr[j-1]){
            arr[j] = arr[j-1]; j--;
        }
        arr[j] = key;
    }
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int size;
    printf("\n-->> Enter the array size: "); scanf("%d", &size);
    int *arr = (int *)calloc(size, sizeof(int));
    printf("\n-->> Enter %d elements of the array: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    printf("\n-->> Array before Insertion Sort: "); display(arr, size); printf("\n");
    InsertionSort(arr, size);
    printf("\n-->> Array after Insertion Sort: "); display(arr, size); printf("\n\n");
    return 0;
}