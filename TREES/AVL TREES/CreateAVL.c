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

    if(P == root){root = Pl;}
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

struct Tree *createAVL(struct Tree *T, int x){

    if(!T){
        struct Tree *P = (struct Tree *)malloc(sizeof(struct Tree));
        P->data = x; P->height = 1;
        P->lchild = P->rchild = NULL;
        return P;
    }

    if(T->data > x){
        T->lchild = createAVL(T->lchild, x);
    }
    else if(T->data < x){
        T->rchild = createAVL(T->rchild, x);
    }

    T->height = NodeHeight(T);

    // LL Rotation
    if(balanceFactor(T)==2 && balanceFactor(T->lchild)==1){
        return LLrotation(T);
    }
    // LR Rotation
    else if(balanceFactor(T)==2 && balanceFactor(T->lchild)==-1){
        return LRrotation(T);
    }

    // RL Rotation
    else if(balanceFactor(T)==-2 && balanceFactor(T->rchild)==1){
        return RLrotation(T);
    }

    // RR Rotation
    else if(balanceFactor(T)==-2 && balanceFactor(T->rchild)==-1){
        return RRrotation(T);
    }

    return T;
}

int height(struct Tree *P){
    if(!P){return 0;}
    int x = height(P->lchild), y = height(P->rchild);
    return x>y?x+1:y+1;
}

struct Tree *inPre(struct Tree *P){
    while(P && P->rchild){
        P = P->rchild;
    }
    return P;
}

struct Tree *inSucc(struct Tree *P){
    while(P && P->lchild){
        P = P->lchild;
    }
    return P;
}

struct Tree *deleteAVL(struct Tree *P, int key){

    if(!P){return NULL;}

    if(P->lchild == NULL && P->rchild == NULL){
        if(root->data == key && root == P){free(root); root = NULL; return NULL;}
        else if(P->data == key){
            free(P); return NULL;
        }
        return P;
    }

    if(P->data < key){
        P->rchild = deleteAVL(P->rchild, key);
    }
    else if(P->data > key){
        P->lchild = deleteAVL(P->lchild, key);
    }
    else{
        if(height(P->lchild) > height(P->rchild)){
            struct Tree *Q = inPre(P->lchild);
            P->data = Q->data;
            P->lchild = deleteAVL(P->lchild, Q->data);
        }
        else{
            struct Tree *Q = inSucc(P->rchild);
            P->data = Q->data;
            P->rchild = deleteAVL(P->rchild, Q->data);
        }
    }

    P->height = NodeHeight(P);

    if(balanceFactor(P) == 2){
        if(balanceFactor(P->lchild) <= 0){
            return LRrotation(P);
        }
        else if(balanceFactor(P->lchild) == 1){
            return LLrotation(P);
        }
    }
    else if(balanceFactor(P) == -2){
        if(balanceFactor(P->rchild) <= 0){
            return RRrotation(P);
        }
        else if(balanceFactor(P->rchild) == 1){
            return RLrotation(P);
        }
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
    printf("\n-->> Enter the no. of nodes to be created in the AVL Tree: "); int n; scanf("%d", &n);
    int x;
    printf("\n-->> Enter %d keys that are to be inserted in the AVL Tree: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        if(!root){root = createAVL(root, x);}
        else{createAVL(root, x);}
    }
    levelOrder(root);
    printf("\n-->> Enter a key for Deletion: "); scanf("%d", &x);
    root = deleteAVL(root, x);
    printf("\n-->> AVL Tree (as per Level Order Traversal): "); levelOrder(root);
}