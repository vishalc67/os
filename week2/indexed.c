#include <stdio.h>

void main() {
    int arr[50], temp[50], i, b, n, count, c = 1;
    for (i = 0; i < 50; i++) arr[i] = 0;
    while (c) {
        a:
        printf("enter index block:");
        scanf("%d", &b);
        if (arr[b] == 0){
            printf("\nenter no.of blocks:");
            scanf("%d", &n);
            arr[b] = 1;
        } else {
            printf("\nblock is already allocated");
            goto a;
        }
        b:
        count = 0;
        printf("\nEnter the blocks to be allocated:");
        for (i = 0; i < n; i++) {
            scanf("%d", &temp[i]);
            if (arr[temp[i]] == 0)
                count++;
        }
        if (count == n){
            for (i = 0; i < n; i++) {
                arr[temp[i]] = 1;
                printf("\n%d\t-->\t%d:1", b, temp[i], arr[temp[i]]);
            }
            printf("\nfile allocated");
            printf("\tfile indexed");
        } else {
            printf("\nNot allocated");
            printf("\nEnter another file indexed");
            goto b;
        }
        printf("\nEnter 0 to exit:");
        scanf("%d", &c);
    }
}
