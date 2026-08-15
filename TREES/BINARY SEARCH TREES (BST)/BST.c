#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree *root;

void createTree(){
    struct Tree *P, *T;
    int x;
    root = (struct Tree *)malloc(sizeof(struct Tree));
    printf("\n--> Enter root data: "); scanf("%d", &x);
    root->data = x; root->lchild = root->rchild = NULL;
    enqueue(root);

    while(!isEmptyQueue()){
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

struct Tree *BSTSearchRec(struct Tree *T, int key){
    if(T == NULL){return NULL;}
    else{
        if(T->data == key){return T;}
        else if(T->data > key){return BSTSearchRec(T->lchild, key);}
        return BSTSearchRec(T->rchild, key);
    }
}

struct Tree *BSTSearchItr(struct Tree *T, int key){
    while(T){
        if(T->data == key){return T;}
        else if(T->data > key){T = T->lchild;}
        else{T = T->rchild;}
    }
    return NULL;
}

void insertBST(struct Tree **P, int ele){
    struct Tree *T = *P;
    struct Tree *R = NULL;  // Tailing pointer
    while (T){
        if(T->data == ele){
            printf("%d already exists in the BST! (Cannot insert duplicates)\n", T->data); return;
        }
        else if(T->data > ele){
            R = T; T = T->lchild;
        }
        else{
            R = T; T = T->rchild;
        }
    }
    struct Tree *D = (struct Tree *)malloc(sizeof(struct Tree));
    D->data = ele; D->lchild = D->rchild = NULL;
    if(R->data > ele){R->lchild = D;}
    else{R->rchild = D;}
    printf("-->> Insertion is Successful!\n");
}

int height(struct Tree *T){
    if(T){
        int x, y;
        x = height(T->lchild); y = height(T->rchild);
        return (x>y)?x+1:y+1;
    }
    return 0;
}

struct Tree *InPre(struct Tree *T){
    while (T && T->rchild){
        T = T->rchild;
    }
    return T;
}

struct Tree *InSucc(struct Tree *T){
    while(T && T->lchild){
        T = T->lchild;
    }
    return T;
}

struct Tree *deleteBST(struct Tree *P, int key){
    struct Tree *Q;

    if(P == NULL){  // Nothing to Delete
        return NULL;
    }
    if(P->lchild == NULL && P->rchild == NULL){
        if(P == root && root->data == key){root = NULL;}
        if(P->data == key){
            free(P);
            return NULL;}
        return P;
    }

    if(P->data > key){
        P->lchild = deleteBST(P->lchild, key);
    }
    else if(P->data < key){
        P->rchild = deleteBST(P->rchild, key);
    }
    else{   // i.e.. the key is found
        // We'll delete the key and will replace it with either inorder successor / inorder predecessor depending on the height of
        // the tree (or subtree)
        if(height(P->lchild) > height(P->rchild)){
            Q = InPre(P->lchild);
            P->data = Q->data;
            P->lchild = deleteBST(P->lchild, Q->data);
        }
        else{
            Q = InSucc(P->rchild);
            P->data = Q->data;
            P->rchild = deleteBST(P->rchild, Q->data);
        }
    }
    return P;
}

// void levelOrder(struct Tree *T){
//     printf("%d ", T->data);
//     enqueue(T);
//     while(!isEmptyQueue()){
//         struct Tree *P = dequeue();
//         if(P->lchild){
//             printf("%d ", P->lchild->data);
//             enqueue(P->lchild);
//         }
//         if(P->rchild){
//             printf("%d ", P->rchild->data);
//             enqueue(P->rchild);
//         }
//     }
// }

void inOrder(struct Tree *T){
    if(T){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

int main(){
    createTree();
    printf("<<--- Binary Search Tree (BST) --->>\n");
    printf("1. Search\n");
    printf("2. Insert\n");
    printf("3. Display (IN Order)\n");
    printf("4. Delete\n");
    printf("5. EXIT\n");
    printf("<<-------------------------------->>\n");
    int ch;
    while(1){
        printf("\nEnter your choice: "); scanf("%d", &ch);
        if(ch == 5){break;}

        switch(ch){
            case 1:
                printf("Enter the search element: "); int key;
                scanf("%d", &key);
                // struct Tree *T = BSTSearchRec(root, key);
                struct Tree *R = BSTSearchItr(root, key);
                if(R){printf("Key is found in the BST!\n");}
                else{printf("Key is NOT found in the BST!\n");}break;

            case 2:
                printf("Enter an element to Insert in the BST: "); int ele;
                scanf("%d", &ele);
                insertBST(&root, ele);break;

            case 3:
                printf("-->> TREE elements (following InOrder Traversal) --> ");
                inOrder(root);break;

            case 4:
                printf("Enter an element to Delete from the BST: ");
                scanf("%d", &ele);
                struct Tree *P = deleteBST(root, ele);
                // if(!P){printf("Node with data %d was not found in the BST!\n", ele);}
                // else{printf("Deletion Successful!\n");}
                break;

            default:
                printf("INVALID CHOICE!\n");
        }
    }
    printf("EXITING....:)\n");
    return 0;
}