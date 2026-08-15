#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *arr, int l, int mid, int h){
    int i = l, j = mid+1, len = 0;
    int res[h+1];
    while(i<=mid && j<=h){
        if(arr[i] == arr[j]){
            res[len++] = arr[i];i++;
            res[len++] = arr[j];j++;
        }
        else if(arr[i] > arr[j]){
            res[len++] = arr[j];j++;
        }
        else{
            res[len++] = arr[i];i++;
        }
    }
    if(i==mid+1){
        while(j<=h){
            res[len++] = arr[j];j++;
        }
    }
    else{
        while(i<=mid){
            res[len++] = arr[i];i++;
        }
    }
    for(int k=0; k<=h; k++){
        arr[k] = res[k];
    }
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);}
}

int main(){
    int size;
    printf("\n-->> Enter the array size: "); scanf("%d", &size);
    int *arr = (int *)calloc(size, sizeof(int));
    printf("\n-->> Enter %d elements of the array 1: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", arr+i);
    }
    
    printf("\n-->> Array before Merge Sort: "); display(arr, size); printf("\n");
    int l = 0, h = size-1;
    MergeSort(arr, 0, (l+h)/2, h);
    printf("\n-->> Array after Merge Sort: "); display(arr, size); printf("\n\n");
    return 0;
}