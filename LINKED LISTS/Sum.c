#include <stdio.h>
#include <stdlib.h>

struct Node {
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
    while(P!=NULL){
        printf("%d ", P->data);
        P = P->next;
    }
}

//ITERATIVE -->
int Isum(struct Node *P){
    int s = 0;
    while(P){
        s += P->data;
        P = P->next;
    }
    return s;
}

//RECURSIVE -->
int Rsum(struct Node *P){
    if(P==NULL){
        return 0;
    }
    return P->data+Rsum(P->next);
}

int main(){
    int A[] = {8, 3, 7, 12, 9};
    create(A, 5);
    printf("-- LINKED LIST --\n");
    display(first);
    printf("\nSum of elements of the Linked List is: %d\n", Rsum(first));
    return 0;
}