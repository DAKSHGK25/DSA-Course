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

void delete(struct Node *P, int pos){
    if(pos!=1){
        struct Node *Q = NULL;
        int i = 1;
        while(i<pos && P!=NULL){
            Q = P;
            P = P->next;
            i++;
        }
        if(P){
            Q->next = P->next;
            P->next = NULL;
            free(P);
            return;
        }
    }
    else{
        struct Node *R = first; //Used to delete from memory
        first = first->next;    //Or even first = P->next also works as initially first = P;
        free(R);
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
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert(first, key);
    }
    printf("-- LINKED LIST --\n");
    display(first);
    int pos;
    printf("\nEnter the Node to be Deleted from the Linked List: ");
    scanf("%d", &pos);
    delete(first, pos);
    printf("-- LINKED LIST AFTER DELETION --\n");
    display(first);
    return 0;
}