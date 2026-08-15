#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *arr1, int *arr2, int *res, int m, int n){
    int i=0, j=0, len = 0;
    while(i<m && j<n){
        if(arr1[i] < arr2[j]){
            res[len++] = arr1[i]; i++;
        }
        else if(arr1[i] > arr2[j]){
            res[len++] = arr2[j]; j++;
        }
        else{
            res[len++] = arr1[i]; i++;
            res[len++] = arr2[j]; j++;
        }
    }
    if(i == m){
        while(j<n){
            res[len++] = arr2[j]; j++;   
        }
        return;
    }
    while(i<m){
        res[len++] = arr1[i]; i++;
    }
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);}
}

int main(){
    int size1, size2;
    printf("\n-->> Enter the array 1 size: "); scanf("%d", &size1);
    int *arr1 = (int *)calloc(size1, sizeof(int));
    printf("\n-->> Enter %d elements of the array 1: ", size1);
    for(int i=0; i<size1; i++){
        scanf("%d", arr1+i);
    }
    printf("\n-->> Enter the array 2 size: "); scanf("%d", &size2);
    int *arr2 = (int *)calloc(size2, sizeof(int));
    printf("\n-->> Enter %d elements of the array 2: ", size2);
    for(int i=0; i<size2; i++){
        scanf("%d", arr2+i);
    }
    printf("\n-->> Array 1 before Merge Sort: "); display(arr1, size1); printf("\n");
    printf("\n-->> Array 2 before Merge Sort: "); display(arr2, size2); printf("\n");
    int size = size1 + size2;
    int res[size];
    MergeSort(arr1, arr2, res, size1, size2);
    printf("\n-->> Array after Merge Sort: "); display(res, size); printf("\n\n");
    return 0;
}