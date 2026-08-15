#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void insert(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
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

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void duplicates(struct Node *P){
    struct Node *Q = NULL;
    Q = P;
    P = P->next;
    while(P){
        if(Q->data == P->data){
            Q->next = P->next;
            free(P);
            P = Q->next;
        }
        else{
            Q = P;
            P = P->next;
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
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert(first, key);
    }
    printf("-- LINKED LIST --\n");
    display(first);
    duplicates(first);
    printf("\n-- LINKED LIST AFTER REMOVING DUPLICATES --\n");
    display(first);
    return 0;
}