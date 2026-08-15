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

void Insert(struct Node *P, int key, int pos){
    struct Node *Q = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;
    while(i<pos-1 && P!=NULL){
        P = P->next;
        i++;
    }
    if(P != NULL){
        //Now i is pos
        Q->data = key;
        Q->next = P->next;
        P->next = Q;
    }
}

void InsertGeneral(struct Node *P, int key, int pos){
    struct Node *Q = (struct Node *)malloc(sizeof(struct Node));
    if(pos == 0){
        Q->data = key;
        Q->next = P;
        first = Q;
        return;
    }
    else{
        Q->data = key;
        int i = 0;
        while(i<pos-1 && P!=NULL){
            P = P->next;
            i++;
        }
        Q->next = P->next;
        P->next = Q;
        return;
    }
}

int main(){
    // int n;
    // printf("Enter the Array size: ");
    // scanf("%d", &n);
    // int A[n];
    // printf("Enter the Array elements: ");
    // for(int i=0; i<n; i++){
    //     scanf("%d", &A[i]);
    // }
    // create(A, n);
    // printf("-- LINKED LIST --\n");
    // display(first);
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key, pos;
        printf("Enter an element to be Inserted: ");
        scanf("%d", &key);
        printf("Enter the node after which Insertion is to be done: ");
        scanf("%d", &pos);
        InsertGeneral(first, key, pos);
    }
    printf("-- LINKED LIST AFTER INSERTION --\n");
    display(first);
    return 0;
}