#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL, *last = NULL;

void insert(struct Node *P, int key){
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

void checkCircular(struct Node *Q, struct Node *P){
    do{
        Q = Q->next;
        P = P->next;
        //Move next if Q is not NULL;
        Q = (Q!=NULL)?Q->next:Q;
    }while(P!=Q && Q!=NULL);
    if(P==Q){
        printf("It's a Circular Linked List!\n");
    }
    else if(Q==NULL){
        printf("It's not a Circular Linked List!\n");
    }
}

//ITERATIVE -->
void display(struct Node *P){
    // while(P->next!=head){
    //     printf("%d ", P->data);
    //     P = P->next;
    // }
    // printf("%d", P->data);
    
    //Above version is correct but the DO-WHILE version is preferred
    do{
        printf("%d ", P->data);
        P = P->next;
    }while(P!=head);
}

//RECURSIVE -->
void displayRec(struct Node *P){
    static int flag = 0;
    if(P!=head){
        printf("%d ", P->data);
        display(P->next);
    }
    else{
        if(flag==0){
            printf("%d ", P->data);
            flag++; //flag = 1;
            display(P->next);
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
        printf("Enter the element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert(head, key);
    }
    //Making the created Linked List CIRCULAR --> making last node to point to 'HEAD' node
    struct Node *P = head;
    while(P->next!=NULL){
        P = P->next;
    }
    P->next = head;
    //checkCircular(head->next, head);
    displayRec(head);
    return 0;
}