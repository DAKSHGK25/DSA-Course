#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree *root = NULL;

int NodeHeight(struct Tree *P){
    int hl = P && P->lchild ? P->lchild->height : 0;
    int hr = P && P->rchild ? P->rchild->height : 0;
    return hl>hr ? hl+1 : hr+1;
}

int balanceFactor(struct Tree *P){
    int hl = P && P->lchild ? P->lchild->height : 0;
    int hr = P && P->rchild ? P->rchild->height : 0;
    return hl-hr;
}

struct Tree *LLrotation(struct Tree *P){
    struct Tree *Pl = P->lchild;
    struct Tree *Plr = Pl->rchild;

    P->lchild = Plr;
    Pl->rchild = P;

    P->height = NodeHeight(P);
    Pl->height = NodeHeight(Pl);

    if(root == P){root = Pl;}
    return Pl;
}

struct Tree *LRrotation(struct Tree *P){
    struct Tree *Pl = P->lchild, *Plr = Pl->rchild;

    Pl->rchild = Plr->lchild;
    Plr->lchild = Pl;
    P->lchild = Plr->rchild;
    Plr->rchild = P;

    P->height = NodeHeight(P);
    Pl->height = NodeHeight(Pl);
    Plr->height = NodeHeight(Plr);

    if(root == P){root = Plr;}
    return Plr;
}

struct Tree *RRrotation(struct Tree *P){
    struct Tree *Pr = P->rchild;
    struct Tree *Prl = Pr->lchild;

    P->rchild = Prl;
    Pr->lchild = P;

    P->height = NodeHeight(P);
    Pr->height = NodeHeight(Pr);

    if(root == P){root = Pr;}
    return Pr;
}

struct Tree *RLrotation(struct Tree *P){
    struct Tree *Pr = P->rchild, *Prl = Pr->lchild;

    P->rchild = Prl->lchild;
    Prl->lchild = P;
    Pr->lchild = Prl->rchild;
    Prl->rchild = Pr;

    P->height = NodeHeight(P);
    Pr->height = NodeHeight(Pr);
    Prl->height = NodeHeight(Prl);

    if(root == P){root = Prl;}
    return Prl;
}

struct Tree *insertAVL(struct Tree *P, int key){

    if(!P){
        struct Tree *Q = (struct Tree *)malloc(sizeof(struct Tree));
        Q->data = key;
        Q->height = 1;
        Q->lchild = Q->rchild = NULL;
        return Q;
    }

    if(P->data > key){
        P->lchild = insertAVL(P->lchild, key);
    }
    else if(P->data < key){
        P->rchild = insertAVL(P->rchild, key);
    }

    P->height = NodeHeight(P);

    if(balanceFactor(P)==2 && balanceFactor(P->lchild)==1){
        return LLrotation(P);
    }
    else if(balanceFactor(P)==2 && balanceFactor(P->lchild)==-1){
        return LRrotation(P);
    }
    else if(balanceFactor(P)==-2 && balanceFactor(P->rchild)==-1){
        return RRrotation(P);
    }
    else if(balanceFactor(P)==-2 && balanceFactor(P->rchild)==1){
        return RLrotation(P);
    }

    return P;
}

void levelOrder(struct Tree *P){
    printf("%d ", P->data);
    enqueue(P);
    while(!isEmptyQueue()){
        struct Tree *Q = dequeue();
        if(Q->lchild){
            printf("%d ", Q->lchild->data);
            enqueue(Q->lchild);
        }
        if(Q->rchild){
            printf("%d ", Q->rchild->data);
            enqueue(Q->rchild);
        }
    }
}


int main(){
    printf("<<----- AVL TREES' OPERATIONS ----->>\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. EXIT\n");
    printf("<<--------------------------------->>\n");
    int ch;
    while(1){
        printf("\n-->> Enter your choice: "); scanf("%d", &ch);

        if(ch==4){break;}

        switch (ch){
        case 1:
            printf("\n-->> Enter a key for Insertion: "); int key; scanf("%d", &key);
            if(!root){root = insertAVL(root, key);}
            else{insertAVL(root, key);}
            break;

        case 2:
            printf("\n-->> Enter a key for Deletion: "); scanf("%d", &key);
            deleteAVL(root, key);

        case 3:
            printf("\n-->> AVL Tree (as per Level Order Traversal): "); levelOrder(root); break;
        
        default:
            break;
        }
    }
    printf("\n-->> EXITING...:)\n");
    return 0;
}