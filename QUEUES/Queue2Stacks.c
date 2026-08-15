#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int data;
    struct Stack *next;
}*top1 = NULL, *top2 = NULL;

void push(struct Stack **S, int ele){
    struct Stack *P = (struct Stack *)malloc(sizeof(struct Stack));
    P->data = ele; P->next = NULL;
    if(*S == NULL){
        *S = P; return;
    }
    P->next = *S;
    *S = P;
    return;
}

int pop(struct Stack **S){
    int x = (*S)->data;
    struct Stack *P = *S;
    *S = (*S)->next;
    free(P);
    return x;
}

int isEmpty(struct Stack **S){
    if(*S == NULL){return 1;}
    return 0;
}

void transfer(){
    while(top1){
        int x = pop(&top1);
        push(&top2, x);
    }
}

void enqueue(int x){
    push(&top1, x);
    printf("Element Inserted successfully!\n"); return;
}

void dequeue(){
    if(isEmpty(&top2)){
        if(isEmpty(&top1)){
            printf("Queue is Empty!\n"); return;
        }
        else{
            transfer();
            int x = pop(&top2);
            printf("%d Deleted successfully!\n", x);
            return;
        }
    }
    int x = pop(&top2);
    printf("%d Deleted successfully!\n", x);
    return;
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
            // case 3:
            //     printf("---- QUEUE ----\n");
            //     display();
            //     printf("\n---------------\n");
            //     break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}