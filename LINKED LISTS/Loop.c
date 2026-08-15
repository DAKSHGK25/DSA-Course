#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int A[], int n){
    for(int i=0; i<n; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        if(first == NULL){
            first = P;
            last = P;
        }
        else{
            last->next = P;
            last = P;
        }
    }
}

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void checkLoop(struct Node *P, struct Node *Q){
    while(P != Q && Q != NULL){
        Q = Q->next->next;
        P = P->next;
    }
    if(P==Q){
        printf("\nIt's a LOOPED Linked List!\n");
    }
    else if(Q==NULL){
        printf("\nIt's not a LOOPED Linked List!\n");
    }
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("---- LINKED LIST ----\n");
    display(first);
    struct Node *t1, *t2;
    t1 = first->next->next; //Points to Node with data 30
    t2 = first->next->next->next->next; //Points to Node with data 50
    t2->next = t1;  //Creating LOOP
    checkLoop(first, first->next);
    return 0;
}