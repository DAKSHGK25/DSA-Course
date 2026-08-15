#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *last = NULL, *third = NULL;

void insert1(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(first == NULL){
        first = P;
        last = P;
    }
    else{
        last->next = P;
        last = P;
    }
}

void insert2(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;
    if(second == NULL){
        second = P;
        last = P;
    }
    else{
        last->next = P;
        last = P;
    }
}

// void insertR(struct Node *P, int key){
//     P = (struct Node *)malloc(sizeof(struct Node));
//     P->data = key;
//     P->next = NULL;
//     if(R == NULL){
//         R = P;
//         last = P;
//     }
//     else{
//         last->next = P;
//         last = P;
//     }
// }

//Using 3rd Linked List -->
// void merge(struct Node *P, struct Node *Q){
//     while(P!=NULL && Q!=NULL){
//         if(P->data < Q->data){
//             insertR(R, P->data);
//             P = P->next;
//         }
//         else if(P->data > Q->data){
//             insertR(R, Q->data);
//             Q = Q->next;
//         }
//         else{
//             insertR(R, P->data);  //or insertR(R, Q->data) also works;
//             P = P->next;
//             Q = Q->next;
//         }
//     }
//     if(P!=NULL){
//         while(P){
//             insertR(R, P->data);
//             P = P->next;
//         }
//     }
//     else if(Q!=NULL){
//         while(Q){
//             insertR(R, Q->data);
//             Q = Q->next;
//         }
//     }
// }

void merge(struct Node *P, struct Node *Q){
    if(P->data > Q->data){
        third = Q;
        last = Q;
        Q = Q->next;
        last->next = NULL;
    }
    else if(P->data < Q->data){
        third = P;
        last = P;
        P = P->next;
        last->next = NULL;
    }
    else{   //Both are Equal --> Choose either P or Q and skip the other to avoid repition
        third = P;  //Choosing P
        last = P;
        P = P->next;
        Q = Q->next;
        last->next = NULL;
    }
    while(P!=NULL && Q!=NULL){
        if(P->data > Q->data){
            last->next = Q;
            last = Q;
            Q = Q->next;
            last->next = NULL;
        }
        else if(P->data < Q->data){
            last->next = P;
            last = P;
            P = P->next;
            last->next = NULL;
        }
        else{
            //either P or Q
            last->next = P;
            last = P;
            P = P->next;
            Q = Q->next;
            last->next = NULL;
        }
    }
    //For remaining Nodes
    if(P != NULL){
        while(P){
            last->next = P;
            last = P;
            P = P->next;
        }
    }
    else if(Q != NULL){
        while(Q){
            last->next = Q;
            last = Q;
            Q = Q->next;
        }
    }
}

void display(struct Node *P){
    while(P){
        printf("%d ", P->data);
        P = P->next;
    }
}

int main(){
    int ch;
    printf("\nFor Linked List 1:\n");
    while (1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert1(first, key);
    }
    printf("\n-- LINKED LIST 1 --\n");
    display(first);
    printf("\nFor Linked List 2:\n");
    while (1){
        printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int key;
        printf("Enter element to be Inserted in the Linked List: ");
        scanf("%d", &key);
        insert2(second, key);
    }
    printf("\n-- LINKED LIST 2 --\n");
    display(second);
    merge(first, second);
    printf("\n-- MERGED LINKED LIST --\n");
    display(third);
    return 0;
}