#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head = NULL, *last = NULL;

void create(int A[], int n){
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head->prev = NULL;
    last = head;

    for(int i=1; i<n; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        P->prev = last;
        last->next = P;
        last = P;
    }
}

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void displayCir(struct Node *P){
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

int main(){
    int A[] = {6, 9, 2, 7, 8};
    create(A, 5);
    //Creating Circular Doubly Linked List
    head->prev = last;
    last->next = head;
    // printf("--- Doubly Linked List ---\n");
    // display(head);
    printf("--- Circular Doubly Linked List ---\n");
    displayCir(head);
    return 0;
}