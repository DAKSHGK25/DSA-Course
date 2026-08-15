#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = P->prev = NULL;

    if(first == NULL){
        first = P;
        last = P;
    }
    else{
        last->next = P;
        P->prev = last;
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

void delete(int pos){
    if(pos == 1){
        struct Node *Q = first;
        first = first->next;
        free(Q);
        first->prev = NULL;
    }
    else{
        int i=1;
        struct Node *P = first, *Q = NULL;
        while(i<pos){
            Q = P;
            P = P->next;
            i++;
        }
        Q->next = P->next;
        if(P->next != NULL){
            P->next->prev = Q;
        }
        else{
            last = Q;   //Required only if you are tring to print the Doubly Linked List in Reverse Order
        }
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
    printf("-- Doubly Linked List (Forward) --\n");
    displayF(first);
    printf("\n-- Doubly Linked List (Backward) --\n");
    displayR(last);
    int pos;
    printf("\nEnter the node that is to be Deleted from the Doubly Linked List: ");
    scanf("%d", &pos);
    delete(pos);
    printf("-- After Deletion --\n");
    printf("-- Doubly Linked List (Forward) --\n");
    displayF(first);
    printf("\n-- Doubly Linked List (Backward) --\n");
    displayR(last);
    return 0;
}