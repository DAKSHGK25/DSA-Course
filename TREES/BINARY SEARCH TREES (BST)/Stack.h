struct Stack{
    struct Tree *data;
    struct Stack *next;
};

void push(struct Tree *T);

struct Tree *pop();

int isEmptyStack();

int stackTop();