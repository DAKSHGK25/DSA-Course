#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void checkSort(struct Node *P){
    struct Node *Q = NULL;
    Q = P;
    P = P->next;
    while(P != NULL){
        if(P->data < Q->data){
            printf("\nThe Linked List is not Sorted!\n");
            return;
        }
        Q = P;
        P = P->next;
    }
    printf("\nThe Linked List is Sorted!\n");
    return;
}

void checkSort2(struct Node *P){
    int x = INT_MIN;    //Inside <limits.h> library
    while(P){
        if(P->data > x){
            x = P->data;
            P = P->next;
        }
        else{
            printf("\nThe Linked List is not Sorted!\n");
            return;
        }
    }
    printf("\nThe Linked List is Sorted!\n");
    return;
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
    checkSort(first);
    checkSort2(first);
    return 0;
}