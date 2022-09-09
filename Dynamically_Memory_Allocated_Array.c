#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i;
    int sum=0;
    int *a;
    printf("Enter the size of the ARRAY\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the array elements 1 by 1\n");
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    for(i=0;i<n;i++){
        sum=sum+(*(a+i));
    }
    printf("Elements are\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(a+i));
    }
    printf("\n");
    printf("SUM=%d\n",sum);
}