#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *arr, int n){
    int flag;
    for(int i=n; i>0; i--){
        flag = 0;
        for(int j=0; j<i-1; j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(&arr[j], &arr[j+1]);
            }
        }
        if(flag == 0){
            return;
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
    printf("\n-->> Array before Bubble Sort: "); display(arr, size); printf("\n");
    BubbleSort(arr, size);
    printf("\n-->> Array after Bubble Sort: "); display(arr, size); printf("\n\n");
    return 0;
}