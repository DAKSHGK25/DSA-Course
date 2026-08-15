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
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void InsertFirst(struct Node *P, int key){
    struct Node *Q = (struct Node *)malloc(sizeof(struct Node));
    Q->data = key;
    first = Q;
    Q->next = P;
}

int main(){
    int n;
    printf("Enter the Array size: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the Array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    create(A, n);
    printf("-- LINKED LIST --\n");
    display(first);
    int key;
    printf("\nEnter an element to be Inserted at first position: ");
    scanf("%d", &key);
    InsertFirst(first, key);
    printf("-- LINKED LIST AFTER INSERTION --\n");
    display(first);
    return 0;
}