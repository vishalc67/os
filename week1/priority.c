#include<stdio.h>
struct pri
{
    int bt,tat,wt,no,ct,pri;
}p[20];

int main(){
    int j,n,i;
    printf("enter no of process");
    scanf("%d",&n);
    printf("enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].bt);
        p[i].no=i+1;
    }
    printf("enter priority:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].pri);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
            if (p[j].pri>p[j+1].pri){
                struct pri temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    p[0].tat=p[0].bt;
    p[0].wt=0;
    p[0].ct=p[0].bt;
    float avgwt=p[0].wt;
    float avgtat=p[0].tat;
    for (i=1;i<n;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
        p[i].tat=p[i].ct;
        p[i].wt=p[i-1].ct;
        avgtat+=p[i].tat;
        avgwt+=p[i].wt;
    }
    printf("------------------------------------------------------");
    printf("\nProcess No Priority Burst Time TAT\tWT\tCompletion Time\n");
    printf("------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].pri,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
    }
    printf("-------------------------------------------------------\n");
    printf("Avgwt:%f \t Avgtat:%f\n",avgwt/n,avgtat/n);
    printf("-------------------------------------------------------\n");
    return 0;
}
