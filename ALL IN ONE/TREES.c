#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Tree *root = NULL;

void createTree(){
    struct Tree *P = NULL, *Q = NULL;
    int x;
    printf("\n-->> Enter the root data: "); scanf("%d", &x);
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = x; root->lchild = root->rchild = NULL;
    enqueue(root);

    while(!isEmptyQueue()){
        P = dequeue();

        printf("\n--> Enter the data of the left child of %d: ", P->data); scanf("%d", &x);
        if(x != -1){
            Q = (struct Tree *)malloc(sizeof(struct Tree));
            Q->data = x; Q->lchild = Q->rchild = NULL;
            P->lchild = Q;
            enqueue(Q);
        }

        printf("--> Enter the data of the right child of %d: ", P->data); scanf("%d", &x);
        if(x != -1){
            Q = (struct Tree *)malloc(sizeof(struct Tree));
            Q->data = x; Q->lchild = Q->rchild = NULL;
            P->rchild = Q;
            enqueue(Q);
        }
    }
    printf("\n-->> Tree created successfully! <<--\n\n");
}

void preOrder(struct Tree *T){
    if(T){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(struct Tree *T){
    if(T){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

void postOrder(struct Tree *T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%d ", T->data);
    }
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

int countNodes(struct Tree *T){
    if(!T){return 0;}
    return countNodes(T->lchild) + countNodes(T->rchild) + 1;
}

int countDeg2Nodes(struct Tree *T){
    if(!T){return 0;}
    if(T->lchild && T->rchild){
        return countDeg2Nodes(T->lchild) + countDeg2Nodes(T->rchild) + 1;
    }
    return countDeg2Nodes(T->lchild) + countDeg2Nodes(T->rchild);
}

int sum(struct Tree *T){
    if(!T){return 0;}
    return sum(T->lchild) + sum(T->rchild) + T->data;
}

int countDeg1Nodes(struct Tree *T){
    if(!T){return 0;}
    if(T->lchild != NULL ^ T->rchild != NULL){
        return countDeg1Nodes(T->lchild) + countDeg1Nodes(T->rchild) + 1;
    }
    return countDeg1Nodes(T->lchild) + countDeg1Nodes(T->rchild);
}

int countLeaf(struct Tree *T){
    if(!T){return 0;}
    if(!(T->lchild || T->rchild)){
        return countLeaf(T->lchild) + countLeaf(T->rchild) + 1;
    }
    return countLeaf(T->lchild) + countLeaf(T->rchild);
}

int countNonLeaf(struct Tree *T){
    if(!T){return 0;}
    if(T->lchild || T->rchild){
        return countNonLeaf(T->lchild) + countNonLeaf(T->rchild) + 1;
    }
    return countNonLeaf(T->lchild) + countNonLeaf(T->rchild);
}

int countLevels(struct Tree *T){
    if(!T){return 0;}
    int x, y;
    x = countLevels(T->lchild);
    y = countLevels(T->rchild);
    return x>y?x+1:y+1;
}

int main() {
    printf("\n<<---- TREE OPERATIONS ---->>\n");
    printf("1. Create Tree\n");
    printf("2. Traversing the tree\n");
    printf("3. Count Nodes\n");
    printf("4. EXIT\n");
    printf("<<------------------------->>\n");

    int ch;
    while (1) {
        printf("\nEnter your choice: "); scanf("%d", &ch);
        if (ch == 4){break;}

        switch (ch) {
            case 1:
                createTree(); break;
            case 2:
                printf("\n<<--- Traversals on Tree --->>\n");
                printf("1. Pre Order\n");
                printf("2. In Order\n");
                printf("3. Post Order\n");
                printf("4. Level Order\n");
                printf("\n<<-------------------------->>\n");
                printf("\nEnter your choice: ");
                int choice; scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("\n-->> Tree (as of Pre Order Traversal): "); preOrder(root); printf("\n");break;
                    case 2:
                        printf("\n-->> Tree (as of In Order Traversal): "); inOrder(root); printf("\n");break;
                    case 3:
                        printf("\n-->> Tree (as of Post Order Traversal): "); postOrder(root); printf("\n");break;
                    case 4:
                        printf("\n-->> Tree (as of Level Order Traversal): "); levelOrder(root); printf("\n");break;
                    default:
                        printf("INVALID CHOICE!\n");
                }
                break;
            case 3:
                printf("Total No. of nodes: %d\n", countNodes(root));
                printf("No. of nodes with degree 2: %d\n", countDeg2Nodes(root));
                printf("Sum of node data: %d\n", sum(root));
                printf("No. of nodes with degree 1: %d\n", countDeg1Nodes(root));
                printf("No. of leaf nodes: %d\n", countLeaf(root));
                printf("No. of non-leaf nodes: %d\n", countNonLeaf(root));
                printf("No. of Levels in the Tree: %d\n", countLevels(root));
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    }
    printf("EXITING....:)\n");
    return 0;
}