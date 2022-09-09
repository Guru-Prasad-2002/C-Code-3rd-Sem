#include<stdio.h>
int add(int a,int b){
    int sum;
    sum=a+b;
    return sum;
}
void main(){
    int (*ptr)(int,int);
    ptr=&add;
    int a,b,s;
    printf("Enter no 1\n");
    scanf("%d",&a);
    printf("Enter no 2\n");
    scanf("%d",&b);
    s=(*ptr)(a,b);
    printf("SUM=%d\n",s);
}
