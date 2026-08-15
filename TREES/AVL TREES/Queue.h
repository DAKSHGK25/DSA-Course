struct Tree{
    struct Tree *lchild;
    int data;
    int height; // Store the height for each node
    struct Tree *rchild;
};

struct Queue{
    struct Tree *data;
    struct Queue *next;
};

void enqueue(struct Tree *T);

struct Tree *dequeue();

int isEmptyQueue();