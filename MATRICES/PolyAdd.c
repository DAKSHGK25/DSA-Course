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

void add(struct Poly P, struct Poly Q, struct Poly *R){
    R->n = (P.n>=Q.n)?P.n:Q.n;
    R->t = (struct Term *)malloc(R->n*sizeof(struct Term));
    int i = 0, j = 0, l = 0;    //i-P, j-Q, l-R
    while(i<P.n || j<Q.n){
        if(P.t[i].e == Q.t[j].e){
            R->t[l].c = P.t[i].c + Q.t[j].c;
            R->t[l].e = P.t[i].e;
            l++; i++; j++;
        }
        else if(P.t[i].e > Q.t[j].e){
            R->t[l].c = P.t[i].c;
            R->t[l].e = P.t[i].e;
            l++; i++;
        }
        else {
            R->t[l].c = Q.t[j].c;
            R->t[l].e = Q.t[j].e;
            l++; j++;
        }
    }
    R->n = l;
}

int main(){
    struct Poly P, Q, R; int x;
    printf("Polynomial P -->\n");
    create(&P);
    printf("Polynomial Q -->\n");
    create(&Q);
    add(P, Q, &R);
    printf("Polynomial R -->\n");
    for(int i=0; i<R.n; i++){
        printf("Term No.%d -->  ", i+1);
        printf("Coefficient: %d | Exponent: %d\n", R.t[i].c, R.t[i].e);
    }
    return 0;
}