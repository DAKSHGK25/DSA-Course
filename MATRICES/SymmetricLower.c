#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *a;
    int size;
};

//Following Lower-Triangle -- Row-Major Formula
void set(struct Matrix *M, int i, int j, int x){
    if(i>=j){
        int loc = (i*(i+1))/2 + j;
        M->a[loc] = x;
    }
}

int get(struct Matrix M, int i, int j){
    int loc;
    if(i>=j){
        loc = (i*(i+1))/2 + j;
    }
    else{
        loc = (j*(j+1))/2 + i;
    }
    return M.a[loc];
}

void display(struct Matrix M){
    int loc;
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            if(i>=j){
                loc = (i*(i+1))/2 + j;
            }
            else{
                loc = (j*(j+1))/2 + i;
            }
            printf("%d ", M.a[loc]);
        }
        printf("\n");
    }
}

int main(){
    struct Matrix M;
    printf("Enter the dimension of 2D Matrix: ");
    scanf("%d", &M.size);
    M.a = (int *)malloc(M.size*sizeof(int));
    int n = (M.size*(M.size+1))/2, x;
    printf("Enter %d elements for the Symmetric Matrix (Using Lower Triangle): ", M.size*M.size);
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            scanf("%d", &x);
            set(&M, i, j, x);
        }
    }
    int r, c;
    printf("Enter row index: ");
    scanf("%d", &r);
    printf("Enter column index: ");
    scanf("%d", &c);
    printf("Element at row %d and column %d is: %d\n", r, c, get(M, r, c));
    printf("Matrix -->\n");
    display(M);
    return 0;
}