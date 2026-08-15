#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b){
    int temp = *a; *a = *b; *b = temp;
}

int partition(int *arr, int l, int h){
    int pivot = arr[l];
    int i = l, j = h;
    do{
        do{i++;}while(arr[i] <= pivot);
        do{j--;}while(arr[j] > pivot);
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }while(i<j);
    swap(&arr[l], &arr[j]);
    return j;   // Current partition index
}

void QuickSort(int *arr, int l, int h){
    if(l<h){
        int j = partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j+1, h);
    }
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);}
}

int main(){
    int size;
    printf("\n-->> Enter the array size: "); scanf("%d", &size);
    int *arr = (int *)calloc(size+1, sizeof(int));
    printf("\n-->> Enter %d elements of the array: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    arr[size] = INT_MAX;
    printf("\n-->> Array before Quick Sort: "); display(arr, size); printf("\n");
    QuickSort(arr, 0, size);
    printf("\n-->> Array after Quick Sort: "); display(arr, size); printf("\n\n");
    return 0;
}