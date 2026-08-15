#include <stdio.h>
#include <stdlib.h>

void insertHeap(int *heap, int n){
    int i = n, temp = heap[n];
    while(i > 1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = temp;
}

void display(int *heap, int n){
    for(int i=1; i<=n; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){
    int n, size;
    printf("\n-->> Enter the size of the Heap: "); scanf("%d", &size);
    printf("\n-->> Enter the no. of elements in the Heap: "); scanf("%d", &n);
    int heap[size], len = n;
    printf("\n-->> Enter the %d keys in Heap: ", n);
    for(int i=1; i<=n; i++){
        scanf("%d", heap+i);
    }
    printf("\n-->> Heap (before Insertion): "); display(heap, len);
    int key;
    printf("\n-->> Enter a key to Insert in Heap: "); scanf("%d", &key);
    heap[++len] = key;
    insertHeap(heap, len);
    printf("\n-->> Heap (after Insertion): "); display(heap, len);
    return 0;
}