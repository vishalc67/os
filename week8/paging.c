#include<stdio.h>
#include<stdlib.h>
void main(){

    int np, ps, i;
    int *sa;
    printf("Enter how many pages: ");
    scanf("%d",&np);
    printf("Enter page size: ");
    scanf("%d",&ps);
    for(i=0;i<np;i++) {
        sa[i] = (int)malloc(ps);
        printf("Page %d address is %d\n", i, sa[i]);
    }
}
