#include<stdio.h>

int * greater(int *a,int* b){
    if(*a>*b){
        return a;
    }
    if(*a<*b){
        return b;
    }
    if(*a==*b){
        return a;
    }
}
void main(){
    int a,b,g;
    printf("Enter no 1\n");
    scanf("%d",&a);
    printf("Enter no 2\n");
    scanf("%d",&b);
    g=*greater(&a,&b);
    printf("Greater of the 2 numbers\n");
    printf("%d",g);
}