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

void display(struct Node *P){
    while(P!=NULL){
        printf("%d ", P->data);
        P = P->next;
    }
}

//ITERATIVE
// int count(struct Node *P){
//     int c = 0;
//     while(P!=NULL){
//         c++;
//         P = P->next;
//     }
//     return c;
// }

int count(struct Node *P){
    static int c = 0;
    if(P!=NULL){
        c++;
        count(P->next);
    }
    return c;
}

int main(){
    int A[] = {3, 5, 7, 10, 15, 18};
    create(A, 6);
    printf("-- LINKED LIST --\n");
    display(first);
    printf("\nThe number of Nodes in Linked List: %d\n", count(first));
    return 0;
}