#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Using Linked Lists
struct Node{
    int data;
    struct Node *next;
}*top = NULL;

int MIN = INT_MAX;

void push(int r){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = r;
    P->next = top;
    top = P;
    if(MIN > r){MIN = r;}
}

int getMin(){
    return MIN;
}

void display(){
    struct Node *P = top;
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

int main(){
    int choice;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- PUSH): ");
        scanf("%d", &choice);
        if(choice == 0){
            break;
        }
        int key;
        printf("Enter an element to Push into the Stack: ");
        scanf("%d", &key);
        push(key);
    }
    printf("--- STACK ---\n");
    display();
    printf("\nMinimum Element inside Stack is: %d\n", getMin());
    return 0;
}