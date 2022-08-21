#include<stdio.h>
void main(){
    int alloc[10][10],need[10][10],max[10][10],flg[10]={0},rv[10];
    int p,r,i,c,j,k,temp,ord[10],ind=0;
    printf("enter no of processes: ");
    scanf("%d",&p);
    printf("enter no of resources: ");
    scanf("%d",&r);
    
    for(i=0;i<p;i++){
        printf("enter allocated resources for processes %d: ",i);
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    }
    for(i=0;i<p;i++){
        printf("enter max resources for processes %d: ",i);
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("enter resource vector: ");
    for(i=0;i<r;i++){
        scanf("%d",&rv[i]);
    }
    c=0;
    while(c<p){
        for(i=0;i<p;i++){
            if(flg[i]==0){
                temp=0;
                for(j=0;j<r;j++){
                    if(need[i][j]<=rv[j]){
                        temp++;
                    }
                }
                if(temp==r){
                    printf("\nresources can be allocated to processes %d",i);
                    for(k=0;k<r;k++){
                        rv[k]+=alloc[i][k];
                    }
                    c++;
                    flg[i]=1;
                }
            }
        }
    }
    printf("\nsystem is in safe state");
}
