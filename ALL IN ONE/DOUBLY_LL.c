#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

void create(int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = P->prev = NULL;

    if(first == NULL){
        first = P;
        last = P;
    }
    else{
        last->next = P;
        P->prev = last;
        last = P;
    }
}

void insert(int pos, int key){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = P->prev = NULL;

    if(pos==0){
        P->next = first;
        first->prev = P;
        first = P;
    }
    else{
        struct Node *Q = first;
        int i=1;
        while(i<3){
            Q = Q->next;
            i++;
        }
        P->next = Q->next;
        if(Q->next!=NULL){
            Q->next->prev = P;
        }
        else{
            last = P;
        }
        P->prev = Q;
        Q->next = P;
    }
}

void delete(int pos){
    if(pos==1){
        struct Node *P = first;
        first = first->next;
        free(P);
        first->prev = NULL;
    }
    else{
        int i=1;
        struct Node *P = first, *Q = NULL;
        while(i<pos){
            Q = P;
            P = P->next;
            i++;
        }
        Q->next = P->next;
        if(P->next!=NULL){
            P->next->prev = Q;
        }
        else{
            last = Q;
        }
        free(P);
    }
}

void display(struct Node *P){
    while(P!=NULL){
        printf("%d ", P->data);
        P = P->next;
    }
}

// void displayReverse(struct Node *P){
//     while(P!=NULL){
//         printf("%d ", P->data);
//         P = P->prev;
//     }
// }

void reverse(struct Node *P){
    while(P){
        struct Node *Q = P->prev;
        P->prev=P->next;
        if(P->next==NULL){
            first = P;
        }
        P->next=Q;
        P=P->prev;
    }
}

int main(){
    printf("----- DOUBLY LINKED LIST -----\n");
    printf("1. Create\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Display\n");
    printf("5. Reverse\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    int choice=0;
    while(choice!=6){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("-------------------\n");
        switch(choice){
            case 1:
                while(1){
                    printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
                    int ch;
                    scanf("%d", &ch);
                    if(ch==0){
                        break;
                    }
                    int key;
                    printf("Enter the element to be inserted in the Doubly Linked List: ");
                    scanf("%d", &key);
                    create(key);
                }
                break;
            case 2:
                printf("Enter the element to be Inserted: ");
                int ele, pos;
                scanf("%d", &ele);
                printf("Enter the position of Insertion: ");
                scanf("%d", &pos);
                insert(pos, ele);
                break;

            case 3:
                printf("Enter the position of Deletion: ");
                scanf("%d", &pos);
                delete(pos);
                break;

            case 4:
                printf("\n-- Doubly Linked List --\n");
                display(first);
                break;

            case 5:
                printf("\n-- Doubly Linked List (Reverse)--\n");
                reverse(first);
                display(first);
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    printf("Exiting.....\n");
    return 0;
}