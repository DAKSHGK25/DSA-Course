#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int A[], int n){
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for(int i=1; i<n; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        last->next = P;
        P->prev = last;
        last = P;
    }
}

void displayBackward(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->prev;
    }
}

void displayForward(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

int length(struct Node *P){
    int c = 0;
    while(P){
        c++;
        P = P->next;
    }
    return c;
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    printf("-- Doubly Linked List (Forward Direction) --\n");
    displayForward(first);
    printf("\n-- Doubly Linked List (Backward Direction) --\n");
    displayBackward(last);
    printf("\nLength of the Doubly Linked List is: %d\n", length(first));
    return 0;
}