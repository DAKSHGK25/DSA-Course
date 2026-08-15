#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int A[], int n){
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        last->next = P;
        last = P;
    }
}

void display(struct Node *P){
    while(P){
        printf("%d -> ", P->data);
        P = P->next;
    }
    printf("NULL\n");
}

struct Node* middle(struct Node *P, struct Node *Q){
    while(Q){
        Q = Q->next;
        Q = (Q!=NULL)?Q->next:Q;
        if(Q!=NULL){
            P = P->next;
        }
    }
    return P;
}

int main(){
    int A[] = {8, 6, 3, 9, 10, 4, 2};
    create(A, 7);
    printf("--- LINKED LIST ---\n");
    display(first);
    struct Node *mid = middle(first, first);
    printf("Middle Element is: %d\n", mid->data);
    return 0;
}