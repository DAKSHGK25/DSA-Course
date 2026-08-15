#include <stdio.h>
#include <stdlib.h>

enum State{
    READY=0, RUNNING, WAITING, TERMINATED
};

struct Process{
    int pid;
    int burstTime;
    int priority;
    enum State state;
};

void st(enum State S){
    switch(S){
        case 0: printf("%-15s", "READY");break;
        case 1: printf("%-15s", "RUNNING");break;
        case 2: printf("%-15s", "WAITING");break;
        case 3: printf("%-15s", "TERMINATED");break;
    }
}

void execute(struct Process *P, int n){
    for(int i=0; i<n; i++){
        P[i].state++;
        printf("-----------------------\n");
        printf("Executing Process %d..\n", P[i].pid);
        printf("State: ");
        st(P[i].state);
        printf("\n-----------------------\n");
        printf("Process %d completed.\n");
        P[i].state+=2;
        printf("State: ");
        st(P[i].state);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process *P = (struct Process *)malloc(n*sizeof(struct Process));
    int wt[n], tat[n];  //Waiting Time, TurnAround Time
    int i=0;
    while(i<n){
        printf("Process %d:\n", i+1);
        printf("PID: ");
        scanf("%d", &P[i].pid);
        printf("Burst Time: ");
        scanf("%d", &P[i].burstTime);
        printf("Priority: ");
        scanf("%d", &P[i].priority);
        P[i].state = 0;
        i++;
        printf("\n");
    }
    int highestPri = P[0].priority, index = -1;
    printf("---- PROCESSES ----\n");
    printf("%-10s%-15s%-15s%-15s\n", "PID", "Burst Time", "Priority", "State");
    for(int i=0; i<n; i++){
        printf("%-10d%-15d%-15d", P[i].pid, P[i].burstTime, P[i].priority);
        st(P[i].state);
        printf("\n");
        if(i == 0){wt[i] = 0;}
        else{
            wt[i] = wt[i-1]+P[i-1].burstTime;
        }
        tat[i] = wt[i]+P[i].burstTime;
        if(P[i].priority < highestPri){
            highestPri = P[i].priority;
            index = i;
        }
    }
    printf("-------------------\n");
    execute(P, n);
    printf("-------------------\n");

    printf("%-10s%-15s%-18s%-20s%-15s\n", "PID", "Burst Time", "Waiting Time", "TurnAround Time", "State");

    for(int i=0; i<n; i++){
        printf("%-10d%-15d%-18d%-20d", P[i].pid, P[i].burstTime, wt[i], tat[i]);
        st(P[i].state);
        printf("\n");
    }
    printf("-------------------\n");
    printf("Highest Priority Process: %d\n", P[index].pid);
    printf("-------------------\n");

    printf("---- STATES SUMMARY ----\n");
    int statecount[4] = {0};
    for(int i=0; i<n; i++){
        statecount[P[i].state]++;
    }
    printf("READY --> %d\n", statecount[0]);
    printf("RUNNING --> %d\n", statecount[1]);
    printf("WAITING --> %d\n", statecount[2]);
    printf("TERMINATED --> %d\n", statecount[3]);
    return 0;
}