#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree *insertBST(struct Tree *P, int key){
    struct Tree *T;
    if(P == NULL){
        T = (struct Tree *)malloc(sizeof(struct Tree));
        T->data = key; T->lchild = T->rchild = NULL;
        return T;
    }
    if(P->data > key){
        P->lchild = insertBST(P->lchild, key);
    }
    else{
        P->rchild = insertBST(P->rchild, key);
    }
    return P;
}

void levelOrder(struct Tree *T){
    printf("%d ", T->data);
    enqueue(T);
    while(!isEmptyQueue()){
        struct Tree *P = dequeue();
        if(P->lchild){
            printf("%d ", P->lchild->data);
            enqueue(P->lchild);
        }
        if(P->rchild){
            printf("%d ", P->rchild->data);
            enqueue(P->rchild);
        }
    }
}

int main(){
    struct Tree *root = NULL;
    root = insertBST(root, 30);
    insertBST(root, 15);
    insertBST(root, 10);
    insertBST(root, 50);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 60);
    printf("BST (as of Level Order Traversal): ");
    levelOrder(root);
    return 0;
}