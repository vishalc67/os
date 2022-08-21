#include<stdio.h>
struct sjf{
    int wt,tat,bt,ct,no;
}p[20];
void main(){
    int n;
    printf("\nEnter number of processes:");
    scanf("%d",&n);
    printf("\nEnter burst times:");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].bt);
        p[i].no = i+1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt > p[j+1].bt){
                struct sjf temp;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    p[0].ct = p[0].bt;
    float AvgTat = p[0].tat;
    float AvgWt = p[0].wt;
    for(int i=1;i<n;i++){
        p[i].ct = p[i-1].ct + p[i].bt;
        p[i].tat = p[i].ct;
        p[i].wt = p[i-1].ct;
        AvgTat += p[i].tat;
        AvgWt += p[i].wt;
    }
    printf("\n--------------------------------------------------");
    printf("\nProcess No Burst times TAT \t WT\t CT");
    for(int i=0;i<n;i++)
        printf("\n%d\t\t %d\t %d\t %d\t %d\t",p[i].no,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
    printf("\n----------------------------------------------------");
    printf("\nAvgWt = %f \t AvgTat = %f",AvgWt/n,AvgTat/n);
    printf("\n----------------------------------------------------");
}
