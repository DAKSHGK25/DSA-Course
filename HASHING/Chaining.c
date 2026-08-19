#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void chaining(struct Node **hash, int *arr, int len){
    for(int i=0; i<len; i++){
        struct Node *P = (struct Node *)malloc(sizeof(struct Node));
        P->data = arr[i]; P->next = NULL;
        if(hash[arr[i]%10] == NULL){
            hash[arr[i]%10] = P;
        }
        else if(arr[i] <= (hash[arr[i]%10])->data){
            P->next = hash[arr[i]%10];
            hash[arr[i]%10] = P;
        }
        else{
            struct Node *Q = hash[arr[i]%10], *R = hash[arr[i]%10]->next;
            while(R){
                if(Q->data < arr[i] && arr[i] <= R->data){
                    P->next = R;
                    Q->next = P;
                    break;
                }
                Q = R; R = R->next;
            }
            if(!R){
                Q->next = P;
            }
        }
    }
}

void delete(struct Node **hash, int key){
    if(!*hash){printf("\n-->> Key is not found!\n"); return;}
    if((*hash)->data == key){
        struct Node *R = *hash;
        *hash = (*hash)->next;
        free(R); return;
    }
    struct Node *P = *hash, *Q = (*hash)->next;
    while(Q){
        if(Q->data == key){
            P->next = Q->next; free(Q); return;
        }
        P = Q; Q = Q->next;
    }
    if(!Q){
        printf("\n-->> Key is not found!\n");
    }
}

void search(struct Node *hash, int key){
    if(!hash){printf("\n-->> Key is not found!\n"); return;}
    struct Node *P = hash;
    while(P){
        if(P->data == key){
            printf("\n-->> Key is found!\n"); return;
        }
        P = P->next;
    }
    printf("\n-->> Key is not found!\n");
}

void display(struct Node **hash){
    printf("<<---------------------------------------------->>\n");
    for(int i=0; i<10; i++){
        printf("%d -->> ", i);
        struct Node *P = hash[i];
        while(P){
            printf("%d -> ", P->data);
            P = P->next;
        }
        printf("NULL\n");
    }
    printf("<<---------------------------------------------->>\n");
}

int main(){
    struct Node **hash = (struct Node **)malloc(10*sizeof(struct Node *));
    for(int i=0; i<10; i++){
        hash[i] = NULL;
    }
    int len; printf("\n-->> Enter the no. of entries: "); scanf("%d", &len);
    int arr[len];
    printf("Enter %d entries: ", len);
    for(int i=0; i<len; i++){
        scanf("%d", arr+i);
    }
    chaining(hash, arr, len);
    printf("\n-->> Hash Table (by Chaining):\n"); display(hash);
    int key;
    printf("\n-->> Enter a key to Search: "); scanf("%d", &key);
    search(hash[key%10], key);
    printf("\n-->> Enter a key to Delete: "); scanf("%d", &key);
    delete(&hash[key%10], key);
    printf("\n-->> Hash Table (after Deleting):\n"); display(hash);
    return 0;
}