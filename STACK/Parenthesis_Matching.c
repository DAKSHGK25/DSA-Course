#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = x;
    P->next = top;
    top = P;
}

void pop(){
    struct Node *P = top;
    top = top->next;
    free(P);
}

char stackTop(){
    if(top != NULL){
        return top->data;
    }
    return ' ';
}

//Only for () --> Parenthesis
// int isBalance(char *r){
//     while(*r != '\0'){
//         if(*r == '('){
//             push(*r);
//         }
//         if(*r == ')' && stackTop() == ' '){
//             return 0;
//         }
//         if(*r == ')' && stackTop() == '('){
//             pop();
//         }
//         r++;
//     }
//     if(top == NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

//General --> for (), {}, []
int isBalance(char *r){
    while(*r != '\0'){
        if(*r == '(' || *r == '[' || *r == '{'){
            push(*r);
        }
        if((*r == ')' || *r == ']' || *r == '}') && top == NULL){
            return 0;
        }
        if((*r == ')' && stackTop() == '(') || (*r == ']' && stackTop() == '[') || (*r == '}' && stackTop() == '{')){
            pop();
        }
        r++;
    }
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char exp[50];
    printf("Enter an Expression: ");
    scanf("%s", exp);
    int r =  isBalance(exp);
    if(r==1){
        printf("The Parenthesis in Expression, Match!\n");
    }
    else{
        printf("The Parenthesis in Expression, DO NOT Match!\n");
    }
    return 0;
}