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

void InsertSorted(struct Node *P, int key){
    struct Node *Q = NULL;
    if(key < first->data){  //To be Inserted before 1st Node
        struct Node *N = (struct Node *)malloc(sizeof(struct Node));
        N->data = key;
        N->next = first;
        first = N;
        return;
    }
    while(P->data < key && P){
        Q = P;
        P = P->next;
    }
    //Need to insert key after the node to which pointer Q is pointing;
    struct Node *N = (struct Node *)malloc(sizeof(struct Node));
    N->data = key;
    N->next = Q->next;
    Q->next = N;
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
        printf("Enter element to be Inserted in the Linked List (follow Ascending Order): ");
        scanf("%d", &key);
        insert(first, key);
    }
    printf("-- LINKED LIST AFTER INSERTION --\n");
    display(first);
    int ele;
    printf("\nEnter an element to be Inserted in the Linked List: ");
    scanf("%d", &ele);
    InsertSorted(first, ele);
    printf("-- SORTED LINKED LIST AFTER INSERTION --\n");
    display(first);
    return 0;
}