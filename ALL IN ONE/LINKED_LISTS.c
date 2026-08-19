#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *last = NULL;

//CREATING LINKED LIST
void create(int A[], int n){
    first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *P, *last;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        P = (struct Node *)malloc(sizeof(struct Node));
        P->data = A[i];
        P->next = NULL;
        last->next = P;
        last = P;
    }
}

//DISPLAYING LINKED LIST
void display(struct Node *P){
    while(P){
        printf("%d -> ", P->data);
        P = P->next;
    }
    printf("NULL\n");
}

int Icount(struct Node *P) {
    int c = 0;
    while(P){
        c++;
        P = P->next;
    }
    return c;
}

// int Rcount(struct Node *P){
//     if(!P){
//         return 0;
//     }
//     else{
//         return 1+Rcount(P->next);
//     }
// }

int Isum(struct Node *P){
    int s = 0;
    while(P){
        s += P->data;
        P = P->next;
    }
    return s;
}

// int Rsum(struct Node *P){
//     if(!P){
//         return 0;
//     }
//     else{
//         return P->data + Rsum(P->next);
//     }
// }

int Imaximum(struct Node *P){
    int max = P->data;
    P = P->next;
    while(P){
        if(max < P->data){
            max = P->data;
        }
        P = P->next;
    }
    return max;
}

// int Rmaximum(struct Node *P){
//     int x;
//     if(P == NULL){
//         return INT_MIN; 
//     }
//     x = Rmaximum(P->next);
//     return (x>P->data)?x:P->data;
// }

// struct Node * Isearch(struct Node *P, int key){
//     while(P){
//         if(P->data == key){
//             return P;
//         }
//         P = P->next;
//     }
//     return NULL;
// }

// struct Node * Rsearch(struct Node *P, int key){
//     if(P == NULL){
//         return P;
//     }
//     if(P->data == key){
//         return P;
//     }
//     Rsearch(P->next, key);
// }

struct Node * optimisedSearch(struct Node *P, int key){
    struct Node *Q = NULL;
    while(P != NULL){
        if(P->data == key){
            Q->next = P->next;
            P->next = first;
            first = P;
            return P;
        }
        Q = P;
        P = P->next;
    }
}

// void insertOne(struct Node *P, int key){
//     struct Node *Q = (struct Node *)malloc(sizeof(struct Node));
//     Q->data = key;
//     Q->next = first;
//     first = Q;
// }

void insertAny(struct Node *P, int key, int pos){
    struct Node *Q = (struct Node *)malloc(sizeof(struct Node));
    Q->data = key;
    int i = 0;
    while(i<pos-1){
        P = P->next;
        i++;
    }
    Q->next = P->next;
    P->next = Q;
}

void insert(struct Node *P, int key){
    P = (struct Node *)malloc(sizeof(struct Node));
    P->data = key;
    P->next = NULL;

    if(first == NULL){  //No nodes still in Linked List
        first = P;
        last = P;
    }
    else{   //Already some Nodes are present
        last->next = P;
        last = P;
    }
}

void deleteAny(struct Node *P, int pos){
    if(pos == 1){
        struct Node *R = first;
        first = first->next;
        free(R);
    }
    else{
        struct Node *Q = NULL;
        int i = 1;
        while(i<pos){
            Q = P;
            P = P->next;
            i++;
        }
        Q->next = P->next;
        free(P);
    }
}

void checkSort(struct Node *P){
    struct Node *Q = NULL;
    Q = P;
    P = P->next;
    while(P){
        if(P->data < Q->data){
            printf("It's an Unsorted Linked List!\n");
            return;
        }
        Q = P;
        P = P->next;
    }
    printf("It's a Sorted Linked List!\n");
}

// void checkSort2(struct Node *P){
//     int x = INT_MIN;
//     while(P){
//         if(P->data < x){
//             printf("It's an Unsorted Linked List!\n");
//             return;
//         }
//         x = P->data;
//         P = P->next;
//     }
//     printf("It's a Sorted Linked List!\n");
// }

void duplicates(struct Node *P){
    struct Node *Q = NULL;
    Q = P;
    P = P->next;
    while(P){
        if(P->data != Q->data){
            Q = P;
            P = P->next;
        }
        Q->next = P->next;
        P = Q->next;
    }
}

void reverse(struct Node *P){
    struct Node *Q = NULL, *R = NULL;
    while(P != NULL){
        R = Q;
        Q = P;
        P = P->next;
        Q->next = R;
    }
    first = Q;
}

void reverseRecursion(struct Node *Q, struct Node *P){
    if(P!=NULL){
        reverseRecursion(P, P->next);
        P->next = Q;
    }
    else{
        first = Q;
    }
}

int main(){
    printf("---- LINKED LISTS OPERATIONS ----\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Count of Nodes\n");
    printf("4. Sum of Elements\n");
    printf("5. Maximum Element\n");
    printf("6. Search\n");
    printf("7. Insert\n");
    printf("8. Delete\n");
    printf("9. Check Sorted\n");
    printf("10. Remove Duplicates\n");
    printf("11. Reverse Linked List\n");
    printf("12. EXIT\n");
    printf("---------------------------------\n");
    int ch = 0;
    while(ch != 12){
        printf("\nEnter you choice Operation: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                while(1){
                    int choice;
                    printf("Enter your choice (0 -- EXIT | 1 -- INSERT): ");
                    scanf("%d", &choice);
                    if(choice != 0 && choice != 1){
                        printf("Invalid Choice!\n");
                        printf("Retry!\n");
                    }
                    else if(choice == 0){
                        break;
                    }
                    else{
                        int x;
                        printf("Enter an element to be Inserted in the Linked List: ");
                        scanf("%d", &x);
                        insert(first, x);
                    }
                }
                break;
            case 2:
                printf("-- LINKED LIST AFTER OPERATION --\n");
                display(first);
                printf("\n");
                break;
            case 3:
                printf("Count of Nodes: %d\n", Icount(first));
                break;
            case 4:
                printf("Sum of all elements of the Linked List: %d\n", Isum(first));
                break;
            case 5:
                printf("Maximum element: %d\n", Imaximum(first));
                break;
            case 6:
                printf("Enter the Search element: ");
                int ele;
                scanf("%d", &ele);
                struct Node *E = optimisedSearch(first, ele);
                if(E){
                    printf("%d found in the Linked List at address %p\n", E->data, &(E->data));
                }
                else{
                    printf("%d is not found in the Linked List\n", ele);
                }
                break;
            case 7:
                printf("Enter an element to be Inserted: ");
                int e, pos;
                scanf("%d", &e);
                printf("Enter the position after which Insertion is to be done: ");
                scanf("%d", &pos);
                insertAny(first, e, pos);
                break;
            case 8:
                printf("\nEnter the Node to be Deleted from the Linked List: ");
                int del;
                scanf("%d", &del);
                deleteAny(first, del);
                break;
            case 9:
                checkSort(first);
                break;
            case 10:
                duplicates(first);
                printf("Duplicates Removed Successfully!\n");
                break;
            case 11:
                reverseRecursion(NULL, first);
                break;
            case 12:
                printf("\n**** LINKED LISTS ****\n");
                break;
            default: 
                printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}