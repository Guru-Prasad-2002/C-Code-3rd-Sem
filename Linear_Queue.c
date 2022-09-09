#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int f=-1,r=-1;
void create();
void enqueue();
void deque();
void display();
void main(){
    int ch;
    printf("LINEAR QUEUE OPERATIONS\n");
    while(1){
        printf("1.CREATE\n2.DISPLAY\n3.ENQUEUE\n4.DEQUEUE\n5.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:enqueue();
            break;
            case 4:deque();
            break;
            case 5:exit(0);
            default:printf("Please enter a valid choice\n");
        }
    }
}
void create(){
int n;
printf("Enter the no of elements to be inserted\n");
scanf("%d",&n);
int i;
if(n>MAX){
    printf("Too Many Elements\n");
    return;
}
for(i=0;i<n;i++){
    enqueue();
}
}
void enqueue(){
if(r==MAX-1){
    printf("FULL\n");
    return;
}
int elem;
printf("Enter the element\n");
scanf("%d",&elem);
if(f==-1 && r==-1){
    r=f=0;
    queue[r]=elem;
    return;
}
else{
    r=r+1;
    queue[r]=elem;
    return;
}
}
void deque(){
if(f==-1 && r==-1){
    printf("EMPTY\n");
    return;
}
if(f==r){
    printf("Deleted Element=%d\n",queue[f]);
    f=r=-1;
    return;
}
else{
    printf("Deleted Element=%d\n",queue[f]);
    f=f+1;
    return;
}
}
void display(){
if(f==-1 && r==-1){
    printf("EMPTY\n");
    return;
}
int i=f;
printf("Elements are\n");
while(i!=r){
    printf("%d\t",queue[i]);
    i=i+1;
}
printf("%d\n",queue[i]);
return;
}