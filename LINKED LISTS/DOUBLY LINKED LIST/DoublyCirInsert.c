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

void displayCir(struct Node *P){
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

void insert(int pos, int ele){
    struct Node *R = (struct Node *)malloc(sizeof(struct Node));
    R->data = ele;
    R->next = R->prev = NULL;

    if(pos == 0){
        R->prev = head->prev;
        head->prev = R;
        R->next = head;
        //last->next = R; Or
        R->prev->next = R;
        head = R;
    }

    else{
        int i = 1;
        struct Node *P = head;
        while(i<pos){
            P = P->next;
            i++;
        }
        R->next = P->next;
        P->next->prev = R;
        P->next = R;
        R->prev = P;
    }
}

int main(){
    int A[] = {6, 9, 2, 7, 8};
    create(A, 5);
    //Creating Circular Doubly Linked List
    head->prev = last;
    last->next = head;
    printf("--- Circular Doubly Linked List ---\n");
    displayCir(head);
    int pos, ele;
    printf("\nEnter an element to be inserted in the Circular Doubly Linked List: ");
    scanf("%d", &ele);
    printf("Enter the position of Insertion: ");
    scanf("%d", &pos);
    insert(pos, ele);
    printf("--- Circular Doubly Linked List (after Insertion) ---\n");
    displayCir(head);
    return 0;
}