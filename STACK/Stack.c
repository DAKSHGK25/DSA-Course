//IMPLEMENTING STACK USING AN ARRAY
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};

void push(struct Stack *Stk, int x){
    if(Stk->top == Stk->size-1){
        printf("Stack Overflow!\n");
        return;
    }
    Stk->s[++(Stk->top)] = x;
}

int pop(struct Stack *Stk){
    int x = -1;
    if(Stk->top == -1){
        printf("Stack Underflow!\n");
    }
    else{
        x = Stk->s[Stk->top];
        Stk->top--;
    }
    return x;
}

int peek(struct Stack Stk, int pos){
    int index = Stk.size - 1 - pos;
    int x = -1;
    if(index < 0){
        printf("Invalid Position!\n");
    }
    else{
        x = Stk.s[index];
    }
    return x;
}

int stackTop(struct Stack Stk){
    if(Stk.top == -1){
        return -1;
    }
    else{
        return Stk.s[Stk.top];
    }
}

int isFull(struct Stack Stk){
    if(Stk.top == Stk.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Stack Stk){
    if(Stk.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void display(struct Stack Stk){
    if(isEmpty(Stk)){
        printf("Stack is Empty!\n");
        return;
    }
    printf("---- STACK (from Top) ----\n");
    for(int i=Stk.top; i>=0; i--){
        printf("%d ", Stk.s[i]);
    }
    printf("\n--------------------------\n");
}

int main(){
    struct Stack Stk;
    printf("Enter the size of Stack: ");
    scanf("%d", &Stk.size);
    Stk.s = (int *)malloc(Stk.size*sizeof(int));
    Stk.top = -1;
    printf("----- STACK OPERATIONS -----\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Stack Top\n5. Is Empty\n6. Is Full\n7. Display Stack\n8. Exit\n");
    printf("----------------------------\n");
    int ch;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch == 8){
            break;}
        switch(ch){
            case 1:
                printf("Enter an element to Push into the Stack: ");
                int x;
                scanf("%d", &x);
                push(&Stk, x);
                break;
            case 2:
                printf("");
                int r = pop(&Stk);
                if(r != -1){
                    printf("Element %d is Poped from the Stack!\n", r);
                }
                break;
            case 3:
                printf("Enter a Peek position: ");
                int pos;
                scanf("%d", &pos);
                int k = peek(Stk, pos);
                if(k != -1){
                    printf("Element at position %d inside the Stack is: %d\n", pos, k);
                }
                break;
            case 4:
                printf("");
                int f = stackTop(Stk);
                if (f == -1){
                    printf("Stack is Empty! No Elements present inside Stack!\n");
                }
                else{
                    printf("Element at the Top of the Stack is: %d\n", f);
                }
                break;
            case 5:
                if(isEmpty(Stk)){
                    printf("Stack is Empty!\n");
                }
                else{
                    printf("Stack is not Empty!\n");
                }
                break;
            case 6:
                if(isFull(Stk)){
                    printf("Stack is Full!\n");
                }
                else{
                    printf("Stack is not Full!\n");
                }
                break;
            case 7:
                display(Stk);
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    }
    printf("Exiting....:)");
    return 0;
}