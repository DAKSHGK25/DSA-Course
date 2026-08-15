#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term{
    int c;  //Coefficient
    int e;  //Exponent
};

struct Poly{
    int n;  //Number of terms
    struct Term *t;
};

void create(struct Poly *P){
    printf("Enter the count of Non-Zero terms: ");
    scanf("%d", &P->n);
    P->t = (struct Term *)malloc(P->n*sizeof(struct Term));
    printf("Enter Polynomial terms --> \n");
    for(int i=0; i<P->n; i++){
        printf("Term No.%d: ", i+1);
        scanf("%d %d", &P->t[i].c, &P->t[i].e);
    }
}

int evaluate(struct Poly P, int x){
    int res = 0;
    for(int i=0; i<P.n; i++){
        res += P.t[i].c*(pow(x, P.t[i].e));
    }
    return res;
}

int main(){
    struct Poly P; int x;
    create(&P);
    printf("Enter the value of Variable 'x': ");
    scanf("%d", &x);
    printf("Result: %d\n", evaluate(P, x));
    return 0;
}