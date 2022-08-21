#include <stdio.h>
void main()
{
    int arr[50],i,sb,len,count,c=1;
    for(int i=0;i<50;i++)arr[i]=0;
    while(c){
        printf("enter starting block:");
        scanf("%d",&sb);
        printf("\nlength of the files : ");
        scanf("%d",&len);
        for(i=0,count=0;i<len;i++){
            if(arr[sb+i]!=1)
                count++;
        }
        if(count==len){
            for(i=0;i<len;i++){
                arr[sb]=1;
                printf("\n%d %d",sb,arr[sb]);
                sb++;
            }
            printf("\nThe file is allocated");
        }else{
            printf("\nThe file is already allocated");
        }
        printf("\nEnter 0 to exit:");
        scanf("%d",&c);
    }
}
