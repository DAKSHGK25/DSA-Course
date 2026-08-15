#include <stdio.h>
#include <stdlib.h>

// MIN HEAP

void insertHeap(int *heap, int n){
    int temp = heap[n], i = n;
    while(i>1 && temp<heap[i/2]){
        heap[i] = heap[i/2]; i /= 2;
    }
    heap[i] = temp;
}

void deleteHeap(int *heap, int n){
    if(n == 0){
        printf("\n-->>Heap is empty!\n");
    }
    int x = heap[1];
    heap[1] = heap[n];
    int i=1, j=2*i;
    while(j<n-1){
        if(heap[j+1] < heap[j]){j += 1;}
        if(heap[i] > heap[j]){
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j; j = 2*i;
        }
        else{
            break;
        }
    }
    heap[n] = x;
}

void displayHeap(int *heap, int n){
    printf("\n-->> HEAP: ");
    for(int i=1; i<=n; i++){
        printf("%d ", heap[i]);
    }
}

int main(){
    int size;
    printf("\n-->> Enter the maximum size of Heap: "); scanf("%d", &size);
    int heap[size], x, len;
    printf("\n-->> Enter the no. of items in the Heap: "); scanf("%d", &len);
    printf("\n-->> Enter %d integers: ", len);
    for(int i=1; i<=len; i++){
        scanf("%d", heap+i);
        insertHeap(heap, i);
    }
    displayHeap(heap, len);
    printf("\n-->> Root successfully Deleted from Heap!\n");
    for(int i=len; i>0; i--){
        deleteHeap(heap, i);
    }
    displayHeap(heap, len);
    return 0;
}