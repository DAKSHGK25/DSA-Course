#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head=NULL, *last=NULL;

void create(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(head == NULL){
        head = P;
        last = P;
    }
    else{
        last->next = P;
        last = P;
    }
}

int count(struct Node *P){
    int c = 0;
    if(head==NULL){
        return 0;
    }
    do{
        c++;
        P = P->next;
    }while(P!=head);
    return c;
}

void display(struct Node *P){
    if(count(head) == 0){
        printf("-\n");
    }
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

void delete(int pos){
    if(pos <= 0 | pos > count(head)){
        printf("Invalid Index of Node!\n");
        return;
    }
    if(pos == 1 && count(head) == 1){
        free(head);
        head = NULL;
        return;
    }
    if(pos == 1){
        struct Node *P = head;
        head = head->next;
        last->next = head;
        free(P);
    }
    else{
        struct Node *P = head->next, *Q = head;
        int i=1;
        while(i<pos-1){
            Q = P;
            P = P->next;
            i++;
        }
        Q->next = P->next;
        free(P);
    }
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
        printf("Enter the element to be Inserted in the Circular Linked List: ");
        scanf("%d", &key);
        create(head, key);
    }
    struct Node *copy = head;
    while(copy->next!=NULL){
        copy = copy->next;
    }
    copy->next = head;
    int pos;
    printf("-- CIRCULAR LINKED LIST --\n");
    display(head);
    printf("\n");
    printf("Enter the Node that is to be Deleted: ");
    scanf("%d", &pos);
    delete(pos);
    printf("-- CIRCULAR LINKED LIST AFTER DELETION --\n");
    display(head);
    return 0;
}