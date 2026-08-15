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

void display(struct Node *P){
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

void insert(int ele, int pos){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = ele;
    P->next = NULL;
    if(pos == 0){
        P->next = head;
        head = P;
        last->next = head;
    }
    else{
        struct Node *Q = head;
        int i = 0;
        while(i<pos-1){
            Q = Q->next;
            i++;
        }
        P->next = Q->next;
        Q->next = P;
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
    int pos, ele;
    printf("-- CIRCULAR LINKED LIST --\n");
    display(head);
    printf("\n");
    printf("Enter the element to be Inserted: ");
    scanf("%d", &ele);
    printf("Enter the position (after which Node) at which it has to be Inserted: ");
    scanf("%d", &pos);
    insert(ele, pos);
    printf("-- CIRCULAR LINKED LIST AFTER INSERTION --\n");
    display(head);
    return 0;
}