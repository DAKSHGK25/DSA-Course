#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

void createBST(struct Tree *T, int *arr, int len){
    struct Tree *P = NULL; int i = 1;
    while(i < len){
        if(T->data > arr[i]){
            P = (struct Tree *)malloc(sizeof(struct Tree));
            P->data = arr[i]; P->lchild = P->rchild = NULL;
            T->lchild = P;
            push(T); T = T->lchild;
            i++;
        }
        else{
            if(!isEmptyStack() && stackTop() > arr[i]){
                P = (struct Tree *)malloc(sizeof(struct Tree));
                P->data = arr[i]; P->lchild = P->rchild = NULL;
                T->rchild = P; T = T->rchild;
                i++;
            }
            else{
                if(isEmptyStack()){
                    P = (struct Tree *)malloc(sizeof(struct Tree));
                    P->data = arr[i]; P->lchild = P->rchild = NULL;
                    T->rchild = P; T = T->rchild;
                    i++;
                }
                else{
                    T = pop();
                }
            }
        }
    }
}

void inOrder(struct Tree *T){
    if(T){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

int main(){
    struct Tree *root = NULL;
    int len;
    printf("\n-->> Enter the no. of nodes in the BST: "); scanf("%d", &len);
    int arr[len];
    printf("Enter %d integers for nodes' data (in PreOrder): ", len);
    for(int i=0; i<len; i++){
        scanf("%d", arr+i);
    }
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = arr[0]; root->lchild = root->rchild = NULL;
    createBST(root, arr, len);
    printf("BST (InOrder Traversal): ");
    inOrder(root);printf("\n");
    return 0;
}