#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie{
    char name[50];
    int price;
    int seats;
    int booked;
    int cost;
};

void cost(struct Movie *M, int n){
    for(int i=0; i<n; i++){
        (*M).cost = (*M).booked*(*M).price;
        M++;
    }
}

int total(struct Movie M[], int n){
    int total = 0;
    for(int i=0; i<n; i++){
        total += M[i].cost;
    }
    return total;
}

int main(){
    int n;
    printf("Enter the number of Movies: ");
    scanf("%d", &n);
    struct Movie M[n];
    int i=1;
    while(i<=n){
        printf("Enter details of Movie %d:\n", i);
        printf("Movie Name: ");
        scanf(" %[^\n]s", M[i-1].name);
        printf("Movie price: ");
        scanf("%d", &M[i-1].price);
        printf("Seats: ");
        scanf("%d", &M[i-1].seats);
        i++;
    }

    int ch;
    do{
        char m[50];int f=0;
        printf("Enter Movie name which is to be booked: ");
        scanf(" %[^\n]s", m);
        while(strlen(m) == 0){
            printf("Invalid name!\n");
            //m[0] = '\0';
            printf("Enter Movie name again: ");
            scanf(" %[^\n]s", m);
        }
        for(int i=0; i<n; i++){
            if(strcmp(M[i].name, m) == 0){
                printf("Enter the number of tickets to be booked: ");
                scanf("%d", &M[i].booked);
                if(M[i].booked > 0 && M[i].booked <= M[i].seats){
                    M[i].seats -= M[i].booked;
                    f=1;
                }
                else{
                    printf("Insufficient availability of seats!\n");
                    f=1;
                    break;
                }
            }
        }
        if(f==0){
            printf("Invalid name!\n");
            continue;
        }
        printf("Do you want to continue (1-Yes / 0-No): ");
        scanf("%d", &ch);
    }while(ch != 0);
    cost(M, n);
    printf("Booking Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s --> Tickets: %d, Cost: %d\n", M[i].name, M[i].booked, M[i].cost);
    }
    printf("Total Bill: %d\n", total(M, n));
    return 0;
}