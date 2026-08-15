#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int ele){
    if((q->rear+1)%q->size == q->front){printf("Queue is Full!\n");return;}
    q->rear = (q->rear+1)%q->size;  // New position of rear in Circular Queue
    q->Q[q->rear] = ele;
    printf("Element Inserted successfully!\n");
    return;
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){printf("Queue is Empty!\n");return x;}
    x = q->Q[q->front];
    q->front = (q->front+1)%q->size;
    return x;
}

void display(struct Queue q){
    int pos = (q.front+1)%q.size;
    while(pos != q.rear){
        printf("%d ", q.Q[pos]);
        pos = (pos+1)%q.size;
    }
    printf("%d ", q.Q[pos]);
}

int main(){
    struct Queue q;
    printf("\n--> Enter the size of Queue: ");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(q.size*sizeof(int));
    q.front = q.rear = 0;  // Initially both are 0;
    //q.Q[q.front] = -1;
    printf("<<--- CIRCULAR QUEUE ADT --->>\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. EXIT\n");
    printf("<<-------------------------->>\n");
    int ch;
    while(1){
        printf("\nEnter your choice: ");
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
                printf("");
                x = dequeue(&q);
                if(x!=-1){printf("Dequeue Successful..\n", x);}
                break;
            case 3:
                printf("---- QUEUE ----\n");
                display(q);
                printf("\n---------------\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}