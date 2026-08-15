#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *P, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        last->next = P;
        last = P;
    }
}

void display(struct Node *P){
    if(P == NULL){
        return;
    }
    else{
        printf("%d ", P->data);
    }
    display(P->next);
}

//ITERATIVE -->
void ISearch(struct Node *P, int key){
    while(P){
        if(P->data == key){
            printf("%d is found in the Likned List!\n", key);
            return;
        }
        P = P->next;
    }
    printf("%d is not found in the Likned List!\n", key);
}

//RECURSIVE -->
struct Node * RSearch(struct Node *P, int key){
    if(P == NULL){
        return P;
    }
    else{
        if(P->data == key){
            return P;
        }
        return RSearch(P->next, key);
    }
}

//OPTIMISED --> MOVE TO HEAD
struct Node *OptimisedHead(struct Node *P, int key){
    struct Node *Q = NULL;
    while(P!=NULL){
        if(P->data == key){
            Q->next = P->next;
            P->next = first;
            first = P;
            return P;
        }
        Q = P;
        P = P->next;
    }

}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    printf("-- LINKED LIST --\n");
    display(first);
    int key;
    printf("\nEnter the Search element: ");
    scanf("%d", &key);
    struct Node *E = OptimisedHead(first, key);
    if(E){
        printf("%d found in the Linked List at address %lu\n", key, E);
    }
    else{
        printf("%d is not found in the Likned List!\n", key);
    }
    display(first);
    return 0;
}