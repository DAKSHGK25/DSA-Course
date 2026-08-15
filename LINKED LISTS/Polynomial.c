#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
}*first1 = NULL, *last1 = NULL, *first2 = NULL, *last2 = NULL, *firstR = NULL, *lastR = NULL;

void insert1(int c, int e){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->coeff = c;
    P->exp = e;
    P->next = NULL;

    if(first1 == NULL){
        first1 = P;
        last1 = P;
    }
    else{
        last1->next = P;
        last1 = P;
    }
}

void insert2(int c, int e){
    struct Node *P = (struct Node *)malloc(sizeof(struct Node));
    P->coeff = c;
    P->exp = e;
    P->next = NULL;

    if(first2 == NULL){
        first2 = P;
        last2 = P;
    }
    else{
        last2->next = P;
        last2 = P;
    }
}

int evaluate(struct Node *P, int val){
    if(P == NULL){
        return 0;
    }
    else{
        return (P->coeff*pow(val, P->exp)) + evaluate(P->next, val);
    }
}

void addition(){
    struct Node *P = first1, *Q = first2, *R;
    while(P != NULL || Q != NULL){
        R = (struct Node *)malloc(sizeof(struct Node));
        if(P!=NULL && Q!=NULL){
            if(P->exp == Q->exp){
                R->coeff = P->coeff + Q->coeff;
                R->exp = P->exp;
                R->next = NULL;
                P = P->next; Q = Q->next;
            }
            else if(P->exp < Q->exp){
                R->coeff = Q->coeff;
                R->exp = Q->exp;
                R->next = NULL;
                Q = Q->next;
            }
            else if(P->exp > Q->exp){
                R->coeff = P->coeff;
                R->exp = P->exp;
                R->next = NULL;
                P = P->next;
            }

            if(firstR==NULL){
                firstR = R;
                lastR = R;
            }
            else{
                lastR->next = R;
                lastR = R;
            }
        }
        else if(P==NULL && Q!=NULL){
            while(Q){
                R = (struct Node *)malloc(sizeof(struct Node));
                R->coeff = Q->coeff;
                R->exp = Q->exp;
                R->next = NULL;
                Q = Q->next;

                if(firstR==NULL){
                    firstR = R;
                    lastR = R;
                }
                else{
                    lastR->next = R;
                    lastR = R;
                }
            }
        }
        else if(P!=NULL && Q==NULL){
            while(P){
                R = (struct Node *)malloc(sizeof(struct Node));
                R->coeff = P->coeff;
                R->exp = P->exp;
                R->next = NULL;
                P = P->next;

                if(firstR==NULL){
                    firstR = R;
                    lastR = R;
                }
                else{
                    lastR->next = R;
                    lastR = R;
                }
            }
        }
    }
}

int main(){
    int ch;
    printf("--> Enter the input for Polynomials with decreasing exponent of varaible <--\n");
    printf("-- POLYNOMIAL - 1 --\n");
    while(1){
        printf("Enter your choice (0 -- EXIT || 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int c, e;
        printf("Enter the Coefficient: ");
        scanf("%d", &c);
        printf("Enter the Exponent: ");
        scanf("%d", &e);
        insert1(c, e);
    }

    printf("-- POLYNOMIAL - 2 --\n");
    while(1){
        printf("Enter your choice (0 -- EXIT || 1 -- INSERT): ");
        scanf("%d", &ch);
        if(ch == 0){
            break;
        }
        int c, e;
        printf("Enter the Coefficient: ");
        scanf("%d", &c);
        printf("Enter the Exponent: ");
        scanf("%d", &e);
        insert2(c, e);
    }

    int val;
    printf("Enter a value of variable: ");
    scanf("%d", &val);
    int n;
    printf("Which polynomial to be evaluated: ");
    scanf("%d", &n);
    if(n == 1){
        printf("Value of the Expression is: %d\n", evaluate(first1, val));
    }
    else{    
        printf("Value of the Expression is: %d\n", evaluate(first2, val));
    }
    printf("On Adding the 2 Polynomials RESULT is: ");
    addition();
    int i=1;
    while(firstR){
        printf("Term %d: Coefficient --> %d | Exponent --> %d\n", i, firstR->coeff, firstR->exp);
        firstR = firstR->next;i++;
    }
    return 0;
}