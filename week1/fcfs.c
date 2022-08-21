#include<stdio.h>
struct fcfs
{
    int bt,at,tat,wt,no,ct;
}p[20];

int main(){
    int j,n,i;
    printf("enter no of process: ");
    scanf("%d",&n);
    printf("enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].bt);
        p[i].no=i+1;
    }
    printf("enter arrival times:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].at);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
            if (p[j].at>p[j+1].at){
                struct fcfs temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    p[0].tat=p[0].bt;
    p[0].wt=p[0].at;
    float avgwt=p[0].wt;
    float avgtat=p[0].tat;
    p[0].ct=p[0].bt;
    for (i=1;i<n;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        avgtat+=p[i].tat;
        avgwt+=p[i].wt;
        
    }
    printf("------------------------------------------------------");
    printf("\nProcess No Burst Time TAT\tWT\tAT\tCompletion Time\n");
    printf("------------------------------------------------------\n");
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].bt,p[i].tat,p[i].wt,p[i].at,p[i].ct);
    printf("-------------------------------------------------------\n");
    printf("Avgwt:%f \t Avgtat:%f\n",avgwt/n,avgtat/n);
    printf("-------------------------------------------------------\n");
    return 0;
}
