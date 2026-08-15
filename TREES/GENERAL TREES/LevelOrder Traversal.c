#include <stdio.h>
#include <stdlib.h>
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

void levelOrder(struct Tree *T){
    printf("%d ", T->data);
    enqueue(T);
    while(!isEmpty()){
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
    createTree();
    printf("-->> TREE elements (following LevelOrder Traversal) --> ");
    levelOrder(root);
    return 0;
}