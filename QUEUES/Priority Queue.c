// Type 1. Limited set of Priorities
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    char data;
    struct Queue *next;
}*front1 = NULL, *rear1 = NULL, *front2 = NULL, *rear2 = NULL, *front3 = NULL, *rear3 = NULL;

void enqueue(struct Queue **front, struct Queue **rear, char x){
    struct Queue *P = (struct Queue *)malloc(sizeof(struct Queue));
    P->data = x; P->next = NULL;
    if(*front == NULL){
        *front = *rear = P; return;
    }
    (*rear)->next = P;
    *rear = P; return;
}

char dequeue(struct Queue **front){
    char x = '\0';
    if(*front == NULL){return x;}
    struct Queue *P = *front;
    x = (*front)->data;
    *front = (*front)->next;
    free(P);
    return x;
}

struct Element{
    int x;  // To store the element
    int priority;   // To store its priority
};

int main(){
    printf("\n-->> No. of Priorities allowed --> 3 [1, 2 & 3]\n");
    int n;
    printf("Enter the number of entries: "); scanf("%d", &n);
    struct Element E[n];
    printf("Enter the Element and its Priority -->\n");
    for(int i=0; i<n; i++){
        printf("Entry No.%d --> ", i+1);
        scanf(" %c %d", &E[i].x, &E[i].priority);
        if(E[i].priority == 1){
            enqueue(&front1, &rear1, E[i].x);
        }
        else if(E[i].priority == 2){
            enqueue(&front2, &rear2, E[i].x);
        }
        else if(E[i].priority == 3){
            enqueue(&front3, &rear3, E[i].x);
        }
    }

    char arr[n]; int i=1, len=0; struct Queue *Q = front1;
    while(i<4){
        while(Q){
            arr[len++] = dequeue(&Q);
        }
        i++;
        if(i==2){Q = front2;}
        else{Q = front3;}
    }

    printf("\n--> The elements in order of their Priority is: ");
    for(int i=0; i<len; i++){
        printf("%c ", arr[i]);
    }
    printf("\n\n");

    return 0;
}