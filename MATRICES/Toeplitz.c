#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *a;
    int size;
};

void set(struct Matrix *M, int i, int j, int x){
    int loc = 0;
    if(i<=j){   //Upper Triangle
        loc = j-i;
        M->a[loc] = x;
    }
    else{   //Lower Triangle
        loc = M->size+i-j-1;
        M->a[loc] = x;
    }
}

int get(struct Matrix M, int i, int j){
    int loc = 0;
    if(i<=j){   //Upper Triangle
        loc = j-i;
    }
    else{
        loc = M.size+i-j-1;
    }
    return M.a[loc];
}

void display(struct Matrix M){
    int loc = 0;
    for(int i=0; i<M.size; i++){
        for(int j=0; j<M.size; j++){
            if(i<=j){
                loc = j-i;
            }
            else{
                loc = M.size+i-j-1;
            }
            printf("%d ", M.a[loc]);
        }
        printf("\n");
    }
}

int main(){
    struct Matrix M;
    printf("Enter the dimension of 2D Array: ");
    scanf("%d", &M.size);
    int x, e = (2*M.size)-1;
    M.a = (int *)malloc(e*sizeof(int));
    printf("Enter %d elements for the Toeplitz Matrix: ", M.size*M.size);
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
    printf("TriDiagonal Matrix -->\n");
    display(M);
    return 0;
}