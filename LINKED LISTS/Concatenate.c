#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *last = NULL;

void insert1(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(first == NULL){
        first = P;
        last = first;
    }
    else{
        last->next = P;
        last = P;
    }
}

void insert2(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(second == NULL){
        second = P;
        last = second;
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

void concatenate(struct Node *P, struct Node *Q){
    while(P->next != NULL){
        P = P->next;
    }
    P->next = Q;
}

int main(){
    int ch;
    printf("\nFor Linked List 1:\n");
    while (1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert1(first, key);
    }
    printf("\n-- LINKED LIST 1 --\n");
    display(first);
    printf("\nFor Linked List 2:\n");
    while (1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert2(second, key);
    }
    printf("\n-- LINKED LIST 2 --\n");
    display(second);
    concatenate(first, second);
    printf("\n-- CONCATENATED LINKED LIST --\n");
    display(first);
    return 0;
}