// A Double Ended Queue --> that Queue where both insertion and deletion can be made from both 'front' as well as 'rear'
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueueFront(struct Queue *Q, int ele){
    if(Q->front == -1 && Q->rear != -1){printf("No space available for Insertion at the start of Queue using Front!\n");return;}
    Q->arr[Q->front--] = ele;
    printf("Element Inserted successfully!\n");return;
}

void enqueueRear(struct Queue *Q, int ele){
    if(Q->rear+1 == Q->size){printf("Queue is Full!\n");return;}
    Q->arr[++(Q->rear)] = ele;
    printf("Element Inserted successfully!\n");return;
}

int dequeueFront(struct Queue *Q){
    int x = -1;
    if(Q->front == Q->rear){printf("Queue is Empty!\n");return x;}
    x = Q->arr[++(Q->front)]; return x;

}

int dequeueRear(struct Queue *Q){
    int x = -1;
    if(Q->rear == Q->front){printf("Queue is Empty!\n");return x;}
    x = Q->arr[Q->rear]; Q->rear--; return x;
}

void display(struct Queue Q){
    for(int i=Q.front+1; i<=Q.rear; i++){
        printf("%d ", Q.arr[i]);
    }
}

int main(){
    struct Queue Q;
    printf("\n--> Enter the size of Queue: ");
    scanf("%d", &Q.size);
    Q.arr = (int *)calloc(Q.size, sizeof(int));
    Q.front = Q.rear = -1;

    printf("<<--- DOUBLE ENDED QUEUE ADT --->>\n");
    printf("1. Enqueue (using Front)\n");
    printf("2. Enqueue (using Rear)\n");
    printf("3. Dequeue (using Front)\n");
    printf("4. Dequeue (using Rear)\n");
    printf("5. Display\n");
    printf("6. EXIT\n");
    printf("<<-------------------------->>\n");
    int ch;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch == 6){
            break;
        }
        switch(ch){
            case 1:
                printf("Enter an element to Insert inside the Queue: ");
                int x;
                scanf("%d", &x);
                enqueueFront(&Q, x);
                break;
            case 2:
                printf("Enter an element to Insert inside the Queue: ");
                scanf("%d", &x);
                enqueueRear(&Q, x);
                break;
            case 3:
                printf("");
                x = dequeueFront(&Q);
                if(x!=-1){printf("Dequeue Successful..\n", x);}
                break;
            case 4:
                printf("");
                x = dequeueRear(&Q);
                if(x!=-1){printf("Dequeue Successful..\n", x);}
                break;
            case 5:
                printf("---- QUEUE ----\n");
                display(Q);
                printf("\n---------------\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}