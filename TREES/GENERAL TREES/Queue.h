struct Tree{
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
};

struct Queue{
    struct Tree *data;
    struct Queue *next;
};

void enqueue(struct Tree *T);

struct Tree *dequeue();

int isEmpty();