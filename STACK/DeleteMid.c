#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top1 = NULL, *top2 = NULL;

void push(char r, int f){
    if(f == 1){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = r;
        P->next = top1;
        top1 = P;
        return;}
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = r;
    P->next = top2;
    top2 = P;
}

void pop(int f){
    if(f == 1){
        struct Node *P = top1;
        top1 = top1->next;
        free(P);
        return;
    }
    struct Node *P = top2;
    top2 = top2->next;
    free(P);
}

char stackTop(int f){
    if(f == 1){
        if(top1 == NULL){
            return ' ';
        }
        return top1->data;}
    if(top2 == NULL){
        return ' ';
    }
    return top2->data;
}

void display(int f){
    struct Node *P = (f == 1)?top1:top2;
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

int len(int f){
    struct Node *P = (f == 1)?top1:top2;
    int c = 0;
    while(P){
        c++;
        P = P->next;
    }
    return c;
}

int DelMid(){
    while(len(1) > len(2)){
        push(stackTop(1), 2);
        pop(1);
    }
    int x = stackTop(2);
    pop(2);
    while(top2){
        push(stackTop(2), 1);
        pop(2);
    }
    return x;
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
        push(key, 1);
    }
    printf("--- STACK BEFORE DELETING MIDDLE ELEMENT ---\n");
    display(1);
    int mid = DelMid();
    printf("\nMiddle Element removed is: %d\n", mid);
    printf("--- STACK AFTER DELETING MIDDLE ELEMENT ---\n");
    display(1);
    return 0;
}