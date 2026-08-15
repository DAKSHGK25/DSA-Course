#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
int Imaximum(struct Node *P){
    int max = P->data;  // or use int max = MIN_INT;
    P = P->next;
    while(P){
        if(max < P->data){
            max = P->data;
        }
        P = P->next;
    }
    return max;
}

//RECURSIVE -->
int Rmaximum(struct Node *P){
    int x;
    if(P == NULL){
        return INT_MIN;
    }
    else{
        x = Rmaximum(P->next);
        return (x>P->data)?x:P->data;
    }
}

int main(){
    int A[] = {8, 3, 7, 12, 9};
    create(A, 5);
    printf("-- LINKED LIST --\n");
    display(first);
    printf("\nMaximum element in the Linked List is: %d\n", Imaximum(first));
    return 0;
}