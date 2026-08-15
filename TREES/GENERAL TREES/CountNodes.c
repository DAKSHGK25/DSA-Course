#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

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
        if(x!=-1){
            T = (struct Tree *)malloc(sizeof(struct Tree));
            T->data = x; T->lchild = T->rchild = NULL;
            P->lchild = T;
            enqueue(T);
        }

        printf("--> Enter the data of right child of %d: ", P->data); scanf("%d", &x);
        if(x!=-1){
            T = (struct Tree *)malloc(sizeof(struct Tree));
            T->data = x; T->lchild = T->rchild = NULL;
            P->rchild = T;
            enqueue(T);
        }
    }
    printf("\n-->> Tree created Successfully! <<--\n\n");
}

void preOrder(struct Tree *T){
    if(T){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
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

int countTotalNodes(struct Tree *T){
    int x, y;
    if(T){
        x = countTotalNodes(T->lchild);
        y = countTotalNodes(T->rchild);
        return x + y + 1;
    }
    return 0;
}

int countDeg2Nodes(struct Tree *T){
    int x, y;
    if(T){
        x = countDeg2Nodes(T->lchild);
        y = countDeg2Nodes(T->rchild);
        if(T->lchild && T->rchild){
            return x + y + 1;   // The current node is considered only if its degree 2
        }
        else{
            return x + y;
        }
    }
    return 0;
}

int sum(struct Tree *T){
    int x, y;
    if(T){
        x = sum(T->lchild);
        y = sum(T->rchild);
        return x + y + T->data;
    }
    return 0;
}

int countLeaf(struct Tree *T){
    int x, y;
    if(T){
        x = countLeaf(T->lchild);
        y = countLeaf(T->rchild);
        if(!(T->lchild || T->rchild)){
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int countNonLeaf(struct Tree *T){
    int x, y;
    if(T){
        x = countNonLeaf(T->lchild);
        y = countNonLeaf(T->rchild);
        if(T->lchild || T->rchild){
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int countDeg1Nodes(struct Tree *T){
    int x, y;
    if(T){
        x = countDeg1Nodes(T->lchild);
        y = countDeg1Nodes(T->rchild);
        if((T->lchild != NULL && T->rchild == NULL) || (T->lchild == NULL && T->rchild != NULL)){
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int levelCount(struct Tree *T){
    int x, y;
    if(T){
        x = levelCount(T->lchild);
        y = levelCount(T->rchild);
        if(x > y){
            return x + 1;
        }
        return y + 1;
    }
    return 0;
}

int main(){
    createTree();
    printf("-->> TREE elements (following Preorder Traversal) --> ");
    preOrder(root);
    printf("\nTotal No. of nodes: %d\n", countTotalNodes(root));
    printf("No. of nodes with degree 2: %d\n", countDeg2Nodes(root));
    printf("No. of nodes with degree 1: %d\n", countDeg1Nodes(root));
    printf("Sum of elements in the Tree: %d\n", sum(root));
    printf("No. of Leaf Nodes: %d\n", countLeaf(root));
    printf("No. of Non-Leaf Nodes: %d\n", countNonLeaf(root));
    printf("No. of levels: %d\n", levelCount(root));
    return 0;
}