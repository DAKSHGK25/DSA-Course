#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree *root = NULL;

void createTree(){
    struct Tree *P, *T;
    int x;
    printf("\n--> Enter root data: "); scanf("%d", &x);
    root = (struct Tree *)malloc(sizeof(struct Tree));
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

void preOrder(struct Tree *P){
    if(P){
        printf("%d ", P->data);
        preOrder(P->lchild);
        preOrder(P->rchild);
    }
}

void inOrder(struct Tree *P){
    if(P){
        inOrder(P->lchild);
        printf("%d ", P->data);
        inOrder(P->rchild);
    }
}

void postOrder(struct Tree *P){
    if(P){
        postOrder(P->lchild);
        postOrder(P->rchild);
        printf("%d ", P->data);
    }
}

int main(){
    createTree();
    printf("-->> TREE elements (following Preorder Traversal) --> ");
    preOrder(root);
    printf("\n-->> TREE elements (following Inorder Traversal) --> ");
    inOrder(root);
    printf("\n-->> TREE elements (following Postorder Traversal) --> ");
    postOrder(root);
    return 0;
}