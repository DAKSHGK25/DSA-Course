#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int size, int *len, int key){
    if(*len == size){
        printf("\n-->> No vacant spaces in the Array for insertion!\n"); return;
    }
    int i=*len;
    while(i>0 && arr[i-1]>=key){
        arr[i] = arr[i-1];
        i--;
    }
    arr[i] = key; (*len)++;
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int size, len;
    printf("\n-->> Enter the maximum array size: "); scanf("%d", &size);
    printf("\n-->> Enter the no. of elements to be stored in the array: "); scanf("%d", &len);
    int *arr = (int *)calloc(size, sizeof(int));
    printf("\n-->> Enter %d elements of the array (in sorted order): ", len);
    for(int i=0; i<len; i++){
        scanf("%d", arr+i);
    }
    printf("\n-->> Array before Insertion Sort: "); display(arr, len); printf("\n");
    int key;
    printf("\n-->> Enter a key to be inserted: "); scanf("%d", &key);
    InsertionSort(arr, size, &len, key);
    printf("\n-->> Array after Insertion Sort: "); display(arr, len); printf("\n\n");
    return 0;
}