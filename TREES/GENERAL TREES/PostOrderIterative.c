#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack{
    long int data;
    struct Stack *next;
}*top = NULL;

struct Tree *root = NULL;

void push(long int T){
    struct Stack *P = (struct Stack *)malloc(sizeof(struct Stack));
    P->data = T; P->next = NULL;
    if(top == NULL){
        top = P; return;
    }
    P->next = top;
    top = P;
    return;
}

long int pop(){
    long int x = top->data;
    struct Stack *P = top;
    top = top->next;
    free(P);
    return x;
}

int isEmptyStack(){
    if(top == NULL){return 1;}
    return 0;
}

void createTree(){
    struct Tree *P, *T;
    long int x;
    root = (struct Tree *)malloc(sizeof(struct Tree));
    printf("\n--> Enter root data: "); scanf("%d", &x);
    root->data = x; root->lchild = root->rchild = NULL;
    enqueue(root);

    while(!isEmpty()){
        P = dequeue();

        printf("\n--> Enter the data of left child of %d: ", P->data); scanf("%d", &x);
        if(x != -1){
            T = (struct Tree *)malloc(sizeof(struct Tree));
            T->data = x; T->lchild = T->rchild = NULL;
            P->lchild = T;
            enqueue(T);
        }

        printf("--> Enter the data of right child of %d: ", P->data); scanf("%d", &x);
        if(x != -1){
            T = (struct Tree *)malloc(sizeof(struct Tree));
            T->data = x; T->lchild = T->rchild = NULL;
            P->rchild = T;
            enqueue(T);
        }
    }
    printf("\n-->> Tree created Successfully! <<--\n\n");
}

void postOrderIterative(struct Tree *T){
    while(T || !isEmptyStack()){
        if(T){
            push((long int)T);
            T = T->lchild;
            }
        else{
            long int x = pop();

            if(x > 0){
                push(-x);
                T = ((struct Tree *)x)->rchild;
            }
            else{
                printf("%d ", ((struct Tree *)(abs(x)))->data);
            }
        }
    }
}

int main(){
    createTree();
    printf("\n-->> TREE elements (following Postorder Traversal) --> ");
    postOrderIterative(root);
    return 0;
}