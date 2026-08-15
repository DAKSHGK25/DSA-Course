#include <stdio.h>
#include <stdlib.h>

//Using Linked Lists
struct Node{
    char data;
    struct Node *next;
}*top = NULL;

void push(char r){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = r;
    P->next = top;
    top = P;
}

void pop(){
    struct Node *P = top;
    top = top->next;
    free(P);
}

char stackTop(){
    if(top == NULL){
        return ' ';
    }
    return top->data;
}

void display(){
    struct Node *P = top;
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

void reverse(){
    struct Node *P = top;
    int c = 0;
    while(P){
        c++;
        P = P->next;
    }

    int A[c];
    P = top;
    int l = 0;
    while(P){
        A[l++] = P->data;
        P = P->next;
    }
    P = top;
    l--;
    while(P){
        P->data = A[l--];
        P = P->next;
    }
}

int main(){
    int ch;
    while(1){
        printf("Enter your choice (0 -- EXIT | 1 -- PUSH): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter an element to Push into the Stack: ");
        scanf("%d", &key);
        push(key);
    }
    printf("--- STACK BEFORE REVERSING ---\n");
    display();
    reverse();
    printf("\n--- STACK AFTER REVERSING ---\n");
    display();
    return 0;
}