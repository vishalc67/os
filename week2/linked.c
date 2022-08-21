#include <stdio.h>
void main()
{
    int arr[50],a,i,n,c=1,b;
    for(int i=0;i<50;i++)arr[i]=0;
    printf("\nenter how many blocks already allocated:");
    scanf("%d",&n);
    printf("\nenter already allocated blocks:");
    for(i=0;i<n;i++){
        scanf("%d",&a);
        arr[a]=1;
    }
    while(c){
        printf("\nenter index starting block and length:");
        scanf("%d %d",&b,&n);
        if(arr[b]==0)
            for(i=0;i<n;i++){
                if(arr[b]!=1){
                    arr[b]=1;
                    printf("\n%d-->%d",b++,arr[b]);
                }else{
                    printf("\nblock %d is already allocated",b);
                    n++,b++;
                }
            }
        else
            printf("\nstarting block is already allocated");
        printf("\nenter 0 to stop program:");
        scanf("%d",&c);
    }
}
