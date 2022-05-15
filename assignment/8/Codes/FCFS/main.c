#include <stdio.h>

struct process{
    int pid;
    int bt;
    int wt, tt;
};

int main() {
    int n;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    int bt[n];
    struct process processes[n];
    for(int i=0 ; i<n; i++){
        printf("Enter cpu burst time for process %d:\n", i+1);
        scanf("%d",&bt[i]);
        struct process p;
        p.bt = bt[i];
        p.pid=i;
        processes[i] = p;
    }

    processes[0].wt=0;
    for(int i=1 ; i<n; i++){
        int wt = 0;
        for(int j=0; j<i ; j++){
            wt += processes[j].bt;
        }
        processes[i].wt=wt;
    }
    for(int i=0 ; i<n; i++){
        processes[i].tt=processes[i].wt + processes[i].bt;
    }


    float wtAvg , ttAvg = 0;
    float wtSum, ttSum = 0;
    for(int i=0 ; i<n; i++){
        wtSum += processes[i].wt;
        ttSum += processes[i].tt;
    }
    wtAvg = wtSum/n;
    ttAvg = ttSum/n;


    printf("Waiting Time Avg = %f\n", wtAvg);
    printf("Turnaround Time Avg = %f\n", ttAvg);

    return 0;
}
