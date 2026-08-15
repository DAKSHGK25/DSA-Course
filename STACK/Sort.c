#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top1 = NULL, *top2 = NULL;

void push(char r, int f){
    if(f == 1){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = r;
        P->next = top1;
        top1 = P;
        return;}
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = r;
    P->next = top2;
    top2 = P;
}

void pop(int f){
    if(f == 1){
        struct Node *P = top1;
        top1 = top1->next;
        free(P);
        return;
    }
    struct Node *P = top2;
    top2 = top2->next;
    free(P);
}

char stackTop(int f){
    if(f == 1){
        if(top1 == NULL){
            return ' ';
        }
        return top1->data;}
    if(top2 == NULL){
        return ' ';
    }
    return top2->data;
}

void display(int f){
    struct Node *P = (f == 1)?top1:top2;
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

//ITERATIVE -->
void ISort(){
    while(top1 != NULL){
        if(top2 == NULL){
            push(stackTop(1), 2);
            pop(1);
        }
        else{
            int x = stackTop(1);
            pop(1);
            while(top2 != NULL && x < stackTop(2)){
                push(stackTop(2), 1);
                pop(2);
            }
            push(x, 2);
        }
    }
    while(top2){
        push(top2->data, 1);
        top2 = top2->next;
    }
}

//RECURSIVE -->
void RSort(){
    if(top1 == NULL){
        while(top2){
            push(top2->data, 1);
            top2 = top2->next;
        }
        return;
    }
    if(top2 == NULL){
        push(stackTop(1), 2);
        pop(1);
    }
    else{
        int x = stackTop(1);
        pop(1);
        while(top2 != NULL && x < stackTop(2)){
            push(stackTop(2), 1);
            pop(2);
        }
        push(x, 2);
    }
    RSort();
}

int main(){
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- PUSH): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter an element to Push into the Stack: ");
        scanf("%d", &key);
        push(key, 1);
    }
    printf("--- STACK BEFORE SORTING ---\n");
    display(1);
    RSort();
    printf("\n--- STACK AFTER SORTING ---\n");
    display(1);
    return 0;
}