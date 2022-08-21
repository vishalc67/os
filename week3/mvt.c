#include <stdio.h>
int main()
{
    int partition[15],size,i=0,c=1;
    printf("\nenter memory to be allocated:");
    scanf("%d",&size);
    while(c){
        printf("\nenter process size:");
        scanf("%d",&partition[i]);
        if(size>partition[i]){
            size=size-partition[i];
            printf("remaining memory is %d",size);
            i++;
        }
        else{
            printf("\nrequired memory is not available");
        }
        printf("\nenter 0 to exit");
        scanf("%d",&c);
        if(c==0)
            printf("\n external fragmentation is %d",size);
    }
    return 0;
}
