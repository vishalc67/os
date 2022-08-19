#include<stdio.h>
int f[10],n,p[50],nf,pgfault=0,idx=0;
float rate;
int check(int temp){
    for(int i=0;i<nf;i++)
        if(temp==f[i])
            return 1;
    return 0;
}
void display(){
    for(int i=0;i<nf;i++)
        if(f[i]!=-1)
            printf(" %d",f[i]);
}
void fifo(){
    for(int i=0;i<n;i++){
        if(check(p[i])==0){
            f[idx++%nf] = p[i];
            pgfault++;
        }
        printf("\n For %d:",p[i]);
        display();
    }
}
void main(){
    printf("\nEnter sequence length:");
    scanf("%d",&n);
    printf("\nEnter sequence:");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("\nEnter number of frames:");
    scanf("%d",&nf);
    for(int i=0;i<nf;i++)
        f[i]=-1;
    fifo();
    rate = pgfault*100/n;
    printf("\nPage faults are:%d\nPage fault rate is %f",pgfault,rate);
}
