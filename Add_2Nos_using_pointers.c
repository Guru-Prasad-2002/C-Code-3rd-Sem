#include<stdio.h>
void main(){
    int a,b;
    int *p,*q;
    int c;
    printf("Enter no 1\n");
    scanf("%d",&a);
    printf("Enter no 2\n");
    scanf("%d",&b);
    p=&a;
    q=&b;
    c=(*p)+(*q);
    printf("Sum is\n%d\n",c);
}