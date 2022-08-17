#include <stdio.h>
int main()
{
    int i,p,a[10],c[15],temp=0,total=0;
    float bs,memory;
    printf("\nenter total memory:");
    scanf("%f",&memory);
    printf("\nenter no. of process:");
    scanf("%d",&p);
    bs=memory/p;
    for(i=0;i<p;i++)
        a[i]=bs;
    for(i=0;i<p;i++){
        label:
        printf("\nenter memory for %d processes:",i);
        scanf("%d",&temp);
        if(temp<=bs){
            c[i]=a[i]-temp;
            a[i]=temp;
            printf("\ninternal fragmentation for this block %d",c[i]);
        }
        else{
            printf("\nrequired memory is not available");
            goto label;
        }
        total=total+c[i];
    }
    printf("\ntotal internal fragmentation %d",total);
    return 0;
}
