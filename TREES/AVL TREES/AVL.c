#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Tree *root = NULL;

int NodeHeight(struct Tree *P){
    int hl = P && P->lchild ? P->lchild->height : 0;
    int hr = P && P->rchild ? P->rchild->height : 0;

    return hl > hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Tree *P){
    int hl = P && P->lchild ? P->lchild->height : 0;
    int hr = P && P->rchild ? P->rchild->height : 0;

    return hl - hr;
}


struct Tree *LLrotation(struct Tree *P){
    struct Tree *Pl = P->lchild;
    struct Tree *Plr = Pl->rchild;

    Pl->rchild = P;
    P->lchild = Plr;

    // Modify heights
    P->height = NodeHeight(P);
    Pl->height = NodeHeight(Pl);

    if(root == P){root = Pl;}
    return Pl;
}


struct Tree *LRrotation(struct Tree *P){
    struct Tree *Pl = P->lchild;
    struct Tree *Plr = Pl->rchild;

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
    struct Tree *Pr = P->rchild;
    struct Tree *Prl = Pr->lchild;

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


struct Tree *insertAVL(struct Tree *T, int x){

    if(!T){
        struct Tree *P = (struct Tree *)malloc(sizeof(struct Tree));
        P->data = x; P->height = 1; // Initially considered height to be starting from 1
        P->lchild = P->rchild = NULL;
        return P;
    }

    if(T->data > x){
        T->lchild = insertAVL(T->lchild, x);
    }
    else if(T->data < x){
        T->rchild = insertAVL(T->rchild, x);
    }

    // Set the height of each node created during returning time
    T->height = NodeHeight(T);

    //LL Rotation
    if(BalanceFactor(T)==2 && BalanceFactor(T->lchild)==1){
        return LLrotation(T);
    }
    //LR Rotation
    else if(BalanceFactor(T)==2 && BalanceFactor(T->lchild)==-1){
        return LRrotation(T);
    }
    
    //RR Rotation
    else if(BalanceFactor(T)==-2 && BalanceFactor(T->rchild)==-1){
        return RRrotation(T);
    }
    
    //RL Rotation
    else if(BalanceFactor(T)==-2 && BalanceFactor(T->rchild)==1){
        return RLrotation(T);
    }

    return T;
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
    root = insertAVL(root, 30);
    insertAVL(root, 10);
    insertAVL(root, 20);

    printf("\n-->> AVL Tree after Rotation (Level Order): "); levelOrder(root);

    return 0;
}