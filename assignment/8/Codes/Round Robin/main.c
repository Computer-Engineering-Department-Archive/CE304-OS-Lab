#include <stdio.h>

struct process{
    int pid;
    int bt;
    int wt, tt;
    int lastRoundTime;
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
        processes[i].lastRoundTime = 0;
    }
    int timeQuantom;
    int time = 0;
    printf("Enter time quantom\n");
    scanf("%d",&timeQuantom);
    int done = 0;
    int i=0;
    while(done==0){
        if(processes[i].bt>=timeQuantom){
            processes[i].bt -= timeQuantom;
            processes[i].wt += (time - processes[i].lastRoundTime );
            //printf("time = %d\n",time);
            //printf("lastRoundTime = %d\n",processes[i].lastRoundTime);
            printf("process %d\n",i+1);
            time += timeQuantom;
            processes[i].lastRoundTime = time;
        }
        else{
            if (processes[i].bt == 0) {
                //do nothing
            } else {
                int temp = processes[i].bt;
                processes[i].bt = 0;
                //printf("time = %d\n",time);
                //printf("lastRoundTime = %d\n",processes[i].lastRoundTime);
                processes[i].wt += (time - processes[i].lastRoundTime );
                printf("process %d\n",i+1);
                time += temp;
                processes[i].lastRoundTime = time;
            }
        }
        i++;
        if(i==n){
            i=0;
        }
        done = 1;
        for(int j=0 ; j<n ; j++){
            if(processes[j].bt !=0){
                done = 0;
            }
        }
    }
    for(int i=0 ; i<n; i++){
        processes[i].tt = bt[i] + processes[i].wt;
    }

    for(int i=0 ; i<n; i++){
        printf("waiting time: %d\n",processes[i].wt);
        printf("turnaround time: %d\n",processes[i].tt);
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
