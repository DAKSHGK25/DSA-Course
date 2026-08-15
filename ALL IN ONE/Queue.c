#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Queue *front = NULL, *rear = NULL;

void enqueue(struct Tree *T){
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->data = T; Q->next = NULL;
    if(front == NULL){
        front = rear = Q; return;
    }
    rear->next = Q;
    rear = Q; return;
}

struct Tree *dequeue(){
    struct Queue *Q = front;
    front = front->next;
    if(front == NULL){rear = NULL;}
    struct Tree *R = Q->data;
    free(Q);
    return R;
}

int isEmptyQueue(){
    if(front == NULL){
        return 1;
    }
    return 0;
}