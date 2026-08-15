#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    if(P == NULL){
        printf("Queue is Full!\n");
        return;
    }
    P->data = x;
    P->next = NULL;

    if(front == NULL){  //First Node
        front = P;
        rear = P;
    }
    else{
        rear->next = P;
        rear = P;
    }
    printf("Element Inserted successfully!\n");
}

void dequeue(){
    int x = -1;
    if(front == NULL){
        printf("Queue is Empty!\n");
        return;
    }
    x = front->data;
    struct Node *P = front;
    front = front->next;
    free(P);
    printf("Element Deleted successfully!\n");
    return;
}

void display(){
    struct Node *P = front;
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

int main(){
    printf("<<--- QUEUE ADT --->>\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. EXIT\n");
    printf("<<----------------->>\n");
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
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("---- QUEUE ----\n");
                display();
                printf("\n---------------\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}