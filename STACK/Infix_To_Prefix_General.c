#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int outStack(char r){
    if(r == '+' || r == '-'){return 1;}
    else if(r == '*' || r == '/'){return 3;}
    else if(r == '^'){return 6;}
    else if(r == '('){return 7;}
    else if(r == ')'){return 0;}
}

int inStack(char r){
    if(r == '+' || r == '-'){return 2;}
    else if(r == '*' || r == '/'){return 4;}
    else if(r == '^'){return 5;}
    else if(r == '('){return 0;}
}

int isOperand(char r){
    if(r == '+' || r == '-' || r == '*' || r == '/' || r == '^' || r == '(' || r == ')'){
        return 0;
    }
    return 1;
}

char *Convert(char *r, int n){
    char *postfix = (char *)malloc((n+1)*sizeof(char));
    int len = 0;
    while(*r != '\0'){
        if(isOperand(*r)){
            postfix[len++] = *r;
        }
        else{
            while(top != NULL && outStack(*r) <= inStack(stackTop())){
                if(outStack(*r) < inStack(stackTop())){
                    postfix[len++] = stackTop();
                    pop();
                }
                else if(outStack(*r) == inStack(stackTop())){
                    pop();
                    r++;
                }
            }
            push(*r);
        }
        r++;
    }
    if(top != NULL){
        while(top){
            postfix[len++] = stackTop();
            pop();
        }
    }
    postfix[len] = '\0';
    return postfix;
}

int Result(int a, int b, char r){
    switch(r){
        case '+': return a+b;break;
        case '-': return a-b;break;
        case '*': return a*b;break;
        case '/': return a/b;break;
        case '^': return pow(a,b);break;
    }
}

int Evaluate(char *s){
    while(*s != '\0'){
        if(isOperand(*s)){
            push(*s);
        }
        else{
            int a = stackTop()-'0'; pop();
            int b = stackTop()-'0'; pop();
            int res =  Result(b, a, *s);
            char s = '0' + res;
            push(s);
        }
        s++;
    }
    return top->data-'0';
}

int main(){
    char infix[50];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    char *postfix = Convert(infix, strlen(infix));
    printf("Postfix Expression is: %s\n", postfix);
    printf("Result: %d\n", Evaluate(postfix));
    return 0;
}