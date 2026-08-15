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

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void reverse(struct Node *P){
    while(P!=NULL){
        struct Node *Q = P->prev;
        P->prev = P->next;
        if(P->next==NULL){
            first = P;
        }
        P->next = Q;
        P = P->prev;
    }
    //first = last; Or use the above
}

int main(){
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch==0){
            break;
        }
        int key;
        printf("Enter the element to be inserted in the Doubly Linked List: ");
        scanf("%d", &key);
        create(key);
    }
    printf("--- DOUBLY LINKED LIST ---\n");
    display(first);
    reverse(first);
    printf("\n--- REVERSED DOUBLY LINKED LIST ---\n");
    display(first);
    return 0;
}