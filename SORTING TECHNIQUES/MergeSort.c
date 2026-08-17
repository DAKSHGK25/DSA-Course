#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int l, int mid, int h){
    int i=l, j=mid+1, res[h+1], g=l;
    while(i<=mid && j<=h){
        if(arr[i] > arr[j]){
            res[g++] = arr[j];j++;
        }
        else if(arr[i] < arr[j]){
            res[g++] = arr[i];i++;
        }
        else if(arr[i] == arr[j]){
            res[g++] = arr[i];i++;
            res[g++] = arr[j];j++;
        }
    }
    if(i == mid+1){
        while(j<=h){
            res[g++] = arr[j];j++;
        }
    }
    else{
        while(i<=mid){
            res[g++] = arr[i];i++;
        }
    }
    for(int k=l; k<=h; k++){
        arr[k] = res[k];
    }
}

void MergeSort(int *arr, int n){
    int l, mid, h, p, i;
    for(p=2; p<=n; p*=2){
        for(i=0; i+p-1<n; i+=p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(arr, l, mid, h);
        }
    }
    if(p/2<n){
        Merge(arr, 0, p/2-1, n-1);
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
    MergeSort(arr, size);
    printf("\n-->> Array after Merge Sort: "); display(arr, size); printf("\n\n");
    return 0;
}