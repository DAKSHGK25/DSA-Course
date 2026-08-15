#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void insertLast(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;

    if(first == NULL){  //No Nodes present as of now in Linked List, this is the first node
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

int main(){
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter an element to be Inserted at Last: ");
        scanf("%d", &key);
        insertLast(first, key);
    }
    printf("-- LINKED LIST AFTER INSERTION --\n");
    display(first);
    return 0;
}