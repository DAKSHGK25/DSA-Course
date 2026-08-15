#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Stack *top = NULL;

void push(struct Tree *T){
    struct Stack *P = (struct Stack *)malloc(sizeof(struct Stack));
    P->data = T; P->next = NULL;
    if(top == NULL){
        top = P; return;
    }
    P->next = top;
    top = P;
    return;
}

struct Tree *pop(){
    struct Tree *x = top->data;
    struct Stack *P = top;
    top = top->next;
    free(P);
    return x;
}

int isEmptyStack(){
    if(top == NULL){return 1;}
    return 0;
}