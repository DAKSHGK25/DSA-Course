#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int Precedence(char r){
    if(r == '+' || r == '-'){
        return 1;
    }
    else if(r == '*' || r == '/'){
        return 2;
    }
    return 3;   //Else its an Operand
}

char *Convert(char *r, int n){
    char *postfix = (char *)malloc((n+1)*sizeof(char));
    int len = 0;
    while(*r != '\0'){
        while(top != NULL && Precedence(*r) <= Precedence(stackTop())){
            postfix[len++] = stackTop();
            pop();
        }
        push(*r);
        r++;
    }
    if(top != NULL){
        while(top != NULL){
            postfix[len++] = stackTop();
            pop();
        }
    }
    postfix[len] = '\0';
    return postfix;
}

int main(){
    char infix[50];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    char *postfix = Convert(infix, strlen(infix));
    printf("Postfix Expression is: %s\n", postfix);
    return 0;
}