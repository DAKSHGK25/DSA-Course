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
    last = first;   //Initially last also points to first
    
    for(int i=1; i<n; i++){
        P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL; //Still there is no next Node;
        last->next = P;
        last = P;
    }
}

//ITERATIVE -->
void display(struct Node *P){
    while(P!=NULL){
        printf("%d ", P->data);
        P = P->next;
    }
}

//RECURSIVE --> TAIL RECURSION
void displayRec(struct Node *P){
    if(P!=NULL){
        printf("%d ", P->data);
        displayRec(P->next);
    }
}

//RECURSIVE --> HEAD RECURSION
void displayRec1(struct Node *P){
    if(P!=NULL){
        displayRec1(P->next);
        printf("%d ", P->data);
    }
}

int main(){
    int A[] = {3, 5, 7, 10, 15, 18};
    create(A, 6);
    printf("-- LINKED LIST --\n");
    printf("Tail Recursion: ");
    displayRec(first);
    printf("\nHead Recursion: ");//Reversing Linked List
    displayRec1(first);
    return 0;
}