#include <stdio.h>
#include <stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *S){
    printf("Enter the dimensions of the Sparse Matrix: ");
    scanf("%d %d", &S->m, &S->n);
    printf("Enter the number of Non-Zero elements: ");
    scanf("%d", &S->num);
    S->e = (struct Element *)malloc(S->num*sizeof(struct Element));
    printf("Enter the row no., column no. and element: ");
    for(int l=0; l<S->num; l++){
        scanf("%d %d %d", &S->e[l].i, &S->e[l].j, &S->e[l].x);
    }
}

void display(struct Sparse S){
    int k =0;
    for(int i=1; i<=S.m; i++){
        for(int j=1; j<=S.n; j++){
            if(i == S.e[k].i && j == S.e[k].j){
                printf("%d ", S.e[k].x);
                k++;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void check(struct Sparse A, struct Sparse B){
    int k = 0, l = 0;
    while(k < A.num && l < B.num){
        if(A.e[k].i != B.e[l].i || A.e[k].j != B.e[l].j || A.e[k].x != B.e[l].x){
            printf("Sparse Matrices are not EQUAL!");
            return;
        }
        k++; l++;
    }
    if(k != A.num || l != B.num){
        printf("Sparse Matrices are not EQUAL!");
        return;
    }
    else{
        printf("Sparse Matrices are EQUAL!");
        return;
    }
}

int main(){
    struct Sparse A, B;
    printf("Sparse Matrix A -->\n");
    create(&A);
    printf("-----------------\n");
    display(A);
    printf("-----------------\n");
    printf("Sparse Matrix B -->\n");
    create(&B);
    printf("-----------------\n");
    display(B);
    printf("-----------------\n");
    check(A, B);
    return 0;
}