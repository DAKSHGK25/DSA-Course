#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int key){
    if(first == NULL){
        first = (struct Node *)malloc(sizeof(struct Node));
        first->data = key;
        first->prev = first->next = NULL;
        last = first;
    }
    else{
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = key;
        P->next = NULL;
        P->prev = last;
        last->next = P;
        last = P;
    }
}

void displayF(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void displayR(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->prev;
    }
}

void insert(int pos, int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = P->prev = NULL;

    if(pos == 0){
        P->next = first;
        first->prev = P;
        first = P;
    }
    else{
        int i=1;
        struct Node *Q = first->next;
        while(i<pos-1){
            Q = Q->next;
            i++;
        }
        P->next = Q->next;
        if(Q->next != NULL){
            Q->next->prev = P;
        }
        else{
            last = P;
        }
        Q->next = P;
        P->prev = Q;
    }
}

int main(){
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter an element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        create(key);
    }
    printf("\n-- Doubly Linked List (Forward) --\n");
    displayF(first);
    printf("\n-- Doubly Linked List (Backward) --\n");
    displayR(last);
    int ele, pos;
    printf("\nEnter an element to be Inserted: ");
    scanf("%d", &ele);
    printf("Enter the node after which Insertion is to be done: ");
    scanf("%d", &pos);
    insert(pos, ele);
    printf("-- After Insertion --\n");
    printf("\n-- Doubly Linked List (Forward) --\n");
    displayF(first);
    printf("\n-- Doubly Linked List (Backward) --\n");
    displayR(last);
    return 0;
}