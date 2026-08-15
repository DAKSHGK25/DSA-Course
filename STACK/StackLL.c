#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));

    if(P == NULL){
        printf("Stack Overflow!\n");
        return;
    }
    else{
        P->data = x;
        P->next = top;
        top = P;
    }
}

int pop(){
    int x = -1;
    if(top == NULL){
        printf("Stack Underflow!\n");
    }
    else{
        x = top->data;
        struct Node *P = top;
        top = top->next;
        free(P);
    }
    return x;
}

int peek(int pos){
    int x = -1;
    struct Node *P = top;
    int i = 1;
    while(P){
        if(i == pos){
            x = P->data;
            break;
        }
        i++;
        P = P->next;
    }
    return x;
}

int stackTop(){
    if(top == NULL){
        return -1;
    }
    else{
        return top->data;
    }
}

int isFull(){
    struct Node *T = (struct Node *)malloc(sizeof(struct Node));
    if(T == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void display(struct Node *P){
    if(isEmpty()){
        printf("Stack is Empty!\n");
        return;
    }
    printf("---- STACK (from Top) ----\n");
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
    printf("\n--------------------------\n");
}


int main(){
    
    printf("----- STACK OPERATIONS -----\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Stack Top\n5. Is Empty\n6. Is Full\n7. Display Stack\n8. Exit\n");
    printf("----------------------------\n");
    int ch;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch == 8){
            break;}
        switch(ch){
            case 1:
                printf("Enter an element to Push into the Stack: ");
                int x;
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("");
                int r = pop();
                if(r != -1){
                    printf("Element %d is Poped from the Stack!\n", r);
                }
                break;
            case 3:
                printf("Enter a Peek position: ");
                int pos;
                scanf("%d", &pos);
                int k = peek(pos);
                if(k != -1){
                    printf("Element at position %d inside the Stack is: %d\n", pos, k);
                }
                else{
                    printf("Invalid Position!\n");
                }
                break;
            case 4:
                printf("");
                int f = stackTop();
                if (f == -1){
                    printf("Stack is Empty! No Elements present inside Stack!\n");
                }
                else{
                    printf("Element at the Top of the Stack is: %d\n", f);
                }
                break;
            case 5:
                if(isEmpty()){
                    printf("Stack is Empty!\n");
                }
                else{
                    printf("Stack is not Empty!\n");
                }
                break;
            case 6:
                if(isFull()){
                    printf("Stack is Full!\n");
                }
                else{
                    printf("Stack is not Full!\n");
                }
                break;
            case 7:
                display(top);
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    }
    printf("Exiting....:)");
    return 0;
}