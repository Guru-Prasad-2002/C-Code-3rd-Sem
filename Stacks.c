#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push();
void pop();
void display();
void create();
void main(){
    printf("Stacks Operations\n");
    int ch;
    do{
        printf("1.CREATE\n2.PUSH\n3.POP\n4.DISPLAY\n5.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();
            break;
            case 2:push();
            break;
            case 3:pop();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("PLEASE ENTER A VALID CHOICE\n");
            break;
        }
    }while(ch!=5);
}

void create(){
   int ch;
   printf("Enter the elements 1 by 1\n");
   do{
      push();
      printf("Do you want to continue?(0/1)\n");
      scanf("%d",&ch);
   }while(ch==1 && top!=MAX-1);
}
void push(){
    int elem;
    if(top==MAX-1){
        printf("STACK IS FULL\n");
        return;
    }
    top=top+1;
    printf("Enter the element\n");
    scanf("%d",&elem);
    stack[top]=elem;
    return;
}
void pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("The deleted element=%d\n",stack[top]);
    top=top-1;
}
void display(){
   if(top==-1){
        printf("Stack is empty\n");
        return;
    } 
    int i=top;
    while(i!=-1){
        printf("%d\t",stack[i]);
        i=i-1;
    }
    printf("\n");
    return;
}