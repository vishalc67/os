#include<stdio.h>
void main()
{
int memsize=15,choice=0,pagesize,nofpage,frameno,offset,logadd,phyadd,i;
int p[100];
printf("\nYour memsize is %d ",memsize);
printf("\nEnter page size:");
scanf("%d",&pagesize);

nofpage=memsize/pagesize;

for(i=0;i<nofpage;i++)
{
printf("\nEnter the frame of page%d:",i+1);
scanf("%d",&p[i]);
}

do
{
printf("\nEnter a logical address:");
scanf("%d",&logadd);
frameno=logadd/pagesize;
offset=logadd%pagesize;
phyadd=(p[frameno]*pagesize)+offset;
printf("\nPhysical address is:%d",phyadd);
printf("\nDo you want to continue(1/0)?:");
scanf("%d",&choice);
}while(choice==1);

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
#include<stdio.h>
void main(){
    int page[50],i,np,nf,ps,off,pno,c = 1;
    printf("\nEnter page size: ");
    scanf("%d",&ps);
    printf("\nEnter the no. of  pages: ");
    scanf("%d",&np);
    printf("\nEnter no. of frames: ");
    scanf("%d",&nf);
    for(i=0;i<np;i++)
        page[i]=-1;
    printf("\nEnter page table");
    printf("\n(Enter frame no as -1 if that page is not present in any frame)");
    printf("\npage no\tframe no");
    for(i=0;i<np;i++){
        printf("\n%d",i);
        scanf("%d",&page[i]);
    }
    while(c){
        printf("\nEnter the logical address(page no & offset):");
        scanf("%d%d",&pno,&off);
        if(page[pno]==-1)
            printf("\nRequired page not available in frames");
        else
            printf("\n\nPhysical address is :%d",page[pno]+off);
        printf("\nEnter 0 for exit:");
        scanf("%d",&c);
    }
}
