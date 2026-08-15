#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(arr[pos] > arr[j]){
                pos = j;
            }
        }
        if(pos!=i){
            swap(&arr[pos], &arr[i]);
        }
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
    printf("\n-->> Array before Selection Sort: "); display(arr, size); printf("\n");
    SelectionSort(arr, size);
    printf("\n-->> Array after Selection Sort: "); display(arr, size); printf("\n\n");
    return 0;
}