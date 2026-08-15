#include <stdio.h>
#include <stdlib.h>

struct Tree {
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
}*root = NULL;

void insertBST(struct Tree **T, int x){

    if(!(*T) && *T == root){
        root = (struct Tree *)malloc(sizeof(struct Tree));
        root->data = x; root->lchild = root->rchild = NULL; return;
    }

    struct Tree *P = *T, *R = NULL;
    while(P){
        R = P;
        if(P->data == x){printf("%d already exists in the BST! (Cannot insert duplicates)\n", P->data); return;}
        else if(P->data > x){
            P = P->lchild;
        }
        else{P = P->rchild;}
    }
    struct Tree *Q = (struct Tree *)malloc(sizeof(struct Tree));
    Q->data = x; Q->lchild = Q->rchild = NULL;
    if(R->data > x){R->lchild = Q; return;}
    R->rchild = Q; return;
}

struct Tree *insertRec(struct Tree *P, int x){

    if(!P){
        struct Tree *Q = (struct Tree *)malloc(sizeof(struct Tree));
        Q->data = x; Q->lchild = Q->rchild = NULL;
        return Q;
    }

    if(P->data > x){
        P->lchild = insertRec(P->lchild, x);
    }
    else if(P->data < x){
        P->rchild = insertRec(P->rchild, x);
    }
    return P;
}

struct Tree *ItrSearch(struct Tree *T, int key){
    while(T){
        if(T->data == key){return T;}
        else if(T->data > key){T = T->lchild;}
        else{T = T->rchild;}
    }
    return T;
}

void inOrder(struct Tree *T){
    if(T){
        inOrder(T->lchild);
        printf("%d ", T->data);
        inOrder(T->rchild);
    }
}

int height(struct Tree *T){
    if(!T){return 0;}
    int x = height(T->lchild), y = height(T->rchild);
    return x>y?x+1:y+1;
}

struct Tree *inPre(struct Tree *T){
    while(T && T->rchild){
        T = T->rchild;
    }
    return T;
}

struct Tree *inSucc(struct Tree *T){
    while(T && T->lchild){
        T = T->lchild;
    }
    return T;
}

struct Tree *deleteBST(struct Tree *T, int x){
    if(!T){return NULL;}

    if(!(T->lchild || T->rchild)){
        if(T == root && root->data == x){
            free(root);
            root = NULL; return root;
        }
        else if(T->data == x){
            free(T);
            return NULL;
        }
    }

    if(T->data > x){
        T->lchild = deleteBST(T->lchild, x);
    }
    else if(T->data < x){
        T->rchild = deleteBST(T->rchild, x);
    }
    else{
        if(height(T->lchild) < height(T->rchild)){
            struct Tree *Q = inSucc(T->rchild);
            T->data = Q->data;
            T->rchild = deleteBST(T->rchild, Q->data);
        }
        else{
            struct Tree *Q = inPre(T->lchild);
            T->data = Q->data;
            T->lchild = deleteBST(T->lchild, Q->data);
        }
    }
    return T;
}

int main() {
    printf("\n<<---- BST OPERATIONS --->>\n");
    printf("1. Create BST\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Display (InOrder Traversal)\n");
    printf("5. Search\n");
    printf("6. EXIT\n");
    printf("<<----------------------->>\n");

    int ch;
    while (1) {
        printf("\n-->> Enter your choice: "); scanf("%d", &ch);
        if (ch==6){break;}

        switch (ch) {
            case 1:
                printf("Enter the initial no. of nodes in the BST: "); int len; scanf("%d", &len);
                int *arr = (int *)calloc(len, sizeof(int));
                printf("Enter %d integers to insert in the BST nodes: ", len);
                for (int i=0; i<len; i++) {
                    scanf("%d", arr+i);
                    insertBST(&root, arr[i]);
                }break;

            case 2:
                printf("Enter a data to Insert: "); int ele; scanf("%d", &ele);
                if (!root){root = insertRec(root, ele);}
                else{insertRec(root, ele);}break;

            case 3:
                printf("Enter a data to Delete: "); scanf("%d", &ele);
                deleteBST(root, ele);break;

            case 4:
                printf("\n-->> BST (InOrder Traversal): ");
                inOrder(root);printf("\n");break;

            case 5:
                printf("Enter a data to Search: "); scanf("%d", &ele);
                struct Tree *P = ItrSearch(root, ele);
                if (P){printf("Data %d is found in the BST\n", ele);}
                else{printf("Data %d is NOT found in the BST\n", ele);}break;

            default:
                printf("INVALID CHOICE!\n");
        }
    }
    printf("EXITING...:)\n");
    return 0;
}