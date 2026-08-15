#include <stdio.h>
#include <stdlib.h>

// MAX HEAP

void Heapify(int *heap, int len){
    int i = len/2;
    while(i > 0){
        int j = 2*i;
        if(j == len){
            if(heap[j] > heap[i]){
                int temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
            }
        }
        while(j < len){
            if(heap[j+1] > heap[j]){j += 1;}
            if(heap[i] < heap[j]){
                int temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
                i = j;
                j = 2*i;
            }
            else{break;}
        }
        i--;
    }
}

void displayHeap(int *heap, int len){
    for(int i=1; i<=len; i++){
        printf("%d ", heap[i]);
    }
}

int main(){
    int size;
    printf("\n-->> Enter the size of Heap: "); scanf("%d", &size);
    int heap[size+1];
    printf("\n-->> Enter %d keys for Creating a Heap: ", size);
    for(int i=1; i<=size; i++){
        scanf("%d", heap+i);
    }
    Heapify(heap, size);
    printf("\n-->> Heap: ");
    displayHeap(heap, size);
    return 0;
}