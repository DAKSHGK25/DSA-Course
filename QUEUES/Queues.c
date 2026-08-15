#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1){   //Full condition
        printf("Queue is Full!\n");
        return;
    }
    q->Q[++(q->rear)] = x;
    printf("Element Inserted successfully!\n");return;
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){    //Empty condition
        printf("Queue is Empty!\n");
    }
    else{
        x = q->Q[++(q->front)];
        printf("Element Deleted successfully!\n");
    }
    return x;
}

void display(struct Queue q){
    for(int i=q.front+1; i<=q.rear; i++){
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    printf("Enter the size of Queue: ");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(q.size*sizeof(int));
    q.front = q.rear = -1;  //Initially both are -1;
    printf("<<--- QUEUE ADT --->>\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. EXIT\n");
    printf("<<----------------->>\n");
    int ch;
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &ch);
        if(ch == 4){
            break;
        }
        switch(ch){
            case 1:
                printf("Enter an element to Insert inside the Queue: ");
                int x;
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("---- QUEUE ----\n");
                display(q);
                printf("---------------\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}