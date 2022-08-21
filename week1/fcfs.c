#include<stdio.h>
struct fcfs{
    int ct,at,tat,wt,no,bt;
}p[20];
void main(){
    int n;
    float AvgWt,AvgTat;
    printf("\nEnter number of process:");
    scanf("%d",&n);
    printf("\nEnter burst times:");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].bt);
        p[i].no = i+1;
    }
    printf("\nEnter arrival times:");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].at);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[i].at>p[j].at) {
                struct fcfs temp;
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    p[0].ct = p[0].bt;
    p[0].wt = p[0].at;
    p[0].tat = p[0].bt;
    AvgTat = p[0].tat;
    AvgWt = p[0].wt;
    for(int i=1;i<n;i++){
        p[i].ct = p[i-1].bt+p[i].bt;
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i-1].ct-p[i].at;
        AvgTat += p[i].tat;
        AvgWt += p[i].wt;
    }
    printf("------------------------------------------------------");
    printf("\nProcess No Burst Time TAT\tWT\tAT\tCompletion Time\n");
    printf("------------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].bt,p[i].tat,p[i].wt,p[i].at,p[i].ct);
    printf("-------------------------------------------------------\n");
    printf("AvgWt:%f \t AvgTat:%f\n",AvgWt/n,AvgTat/n);
    printf("-------------------------------------------------------\n");


}
