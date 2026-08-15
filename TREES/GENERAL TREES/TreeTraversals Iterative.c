#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

struct Tree *root = NULL;

void createTree(){
    struct Tree *P, *T;
    int x;
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

void preOrderIterative(struct Tree *T){
    while(T || !isEmptyStack()){
        if(T){
            printf("%d ", T->data);
            push(T);
            T = T->lchild;
        }
        else{
            T = pop();
            T = T->rchild;
        }
    }
}

void inOrderIterative(struct Tree *T){
    while(T || !isEmptyStack()){
        if(T){
            push(T);
            T = T->lchild;
        }
        else{
            T = pop();
            printf("%d ", T->data);
            T = T->rchild;
        }
    }
}

int main(){
    createTree();
    printf("-->> TREE elements (following Preorder Traversal) --> ");
    preOrderIterative(root);
    printf("\n-->> TREE elements (following Inorder Traversal) --> ");
    inOrderIterative(root);
    return 0;
}