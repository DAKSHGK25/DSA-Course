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
    int k = 0;
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

void multiply(struct Sparse A, struct Sparse B, struct Sparse *C){
    if(A.n != B.m){
        printf("Multipliaction of Sparse Matrices not possible!");
        return;
    }
    else{
        C->m = A.m;
        C->n = B.n;
        C->num = C->m*C->n;
    }
    C->e = (struct Element *)calloc(C->num, sizeof(struct Element));
    int a = 0, c = 0, sum = 0, ele = 0;
    while(a < A.num){
        int l, bcol;
        for(l=0; l<B.num; l++){
            if(A.e[a].j == B.e[l].i && B.e[l].j == bcol){
                sum += A.e[a].x * B.e[l].x;
                C->e[c].i = A.e[a].i;
                C->e[c].j = B.e[l].j;
            }
        }
        C->e[c].x = sum; ele++;
        a++; sum = 0; c++;
    }
    C->num = ele;
}

int main(){
    struct Sparse A, B, C;
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
    multiply(A, B, &C);
    printf("Sparse Matrix on Multiplication -->\n");
    printf("-----------------\n");
    display(C);
    printf("-----------------\n");
    return 0;
}