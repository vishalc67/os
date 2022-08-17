#include<stdio.h>
int n,nf,in[100],p[50],i,j,k,pgfaultcnt=0,least[50];

int isHit(int data){
    for(j=0; j<nf; j++)
        if(p[j]==data)
            return 1;
    return 0;
}
void dispPages(){
    for (k=0; k<nf; k++)
        if(p[k]!=9999)
            printf(" %d",p[k]);
}
void repeat(){
    for(j=0; j<nf; j++){
        int pg=p[j];
        int found=0;
        for(k=i-1; k>=0; k--){
            if(pg==in[k]){
                least[j]=k;
                found=1;
                break;
            }
            else
                found=0;
        }
        if(!found)
            least[j]=-9999;
    }
    int min=9999;
    int repindex;
    for(j=0; j<nf; j++)
        if(least[j]<min){
            min=least[j];
            repindex=j;
        }
    p[repindex]=in[i];
}
void lru(){
    for(i=0; i<n; i++){
        printf("\nFor %d :",in[i]);
        if(isHit(in[i])==0){
            repeat();
            pgfaultcnt++;
            dispPages();
        }
        else{
            // repeat();
            dispPages();
            printf(" NO Fault!");
        }
    }
}

int main(){
    printf("Enter length of page reference sequence:");
    scanf("%d",&n);
    printf("Enter the page reference sequence:");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
    printf("Enter no of frames:");
    scanf("%d",&nf);
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
    lru();
    printf("\nTotal no of page faults:%d",pgfaultcnt);
    float pfr = pgfaultcnt*100/n;
    printf("\nPage Fault Rate:%f",pfr);
    return 0;
}
