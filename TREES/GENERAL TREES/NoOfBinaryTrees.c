#include <stdio.h>
#include <stdlib.h>

// Using the Catalan No.
int nCr(int n, int r){
    if(r == 0 || n == r){return 1;}
    return nCr(n-1, r-1) + nCr(n-1, r);
}

// Using the Memoisation technique
int NTreesMemo(int *f, int n){
    if(f[n] != -1){return f[n];}

    if(n <= 1){
        f[n] = 1;
        return 1;
    }
    else{
        int i=1, res = 0;
        while(i<=n){
            if(f[i-1] == -1){
                f[i-1] = NTreesMemo(f, i-1);
            }
            if(f[n-i] == -1){
                f[n-i] = NTreesMemo(f, n-i);
            }
            res += f[i-1]*f[n-i];
            i++;
        }
        f[n] = res;
        return f[n];
        
    }
}

int main(){
    int n;
    printf("\n-->> Enter the no. of Nodes: "); scanf("%d", &n);
    // int binTree = nCr(2*n, n)/(n+1);
    int f[50];
    for(int i=0; i<50 ; i++){
        f[i] = -1;
    }
    int binTree = NTreesMemo(f, n);
    printf("-->> No. of Binary Trees that can be generated (unlabelled nodes) are: %d\n", binTree);
    return 0;
}