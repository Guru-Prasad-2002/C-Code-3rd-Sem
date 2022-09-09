#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int f=-1,r=-1;
void create();
void enqueue();
void deque();
void display();
void main(){
    int ch;
    printf("CIRCULAR QUEUE OPERATIONS\n");
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
int n,i;
printf("Enter the no of elements\n");
scanf("%d",&n);
if(n>MAX){
    printf("Too many elements\n");
    return;
}
for(i=0;i<n;i++){
    enqueue();
}
return;
}
void enqueue(){
int elem;
if((r+1)%MAX==f){
    printf("FULL\n");
    return;
}
if(f==-1 && r==-1){
    printf("Enter the element\n");
    scanf("%d",&elem);
    f=0;
    r=0;
    q[r]=elem;
    return;
}
else{
    printf("Enter the element\n");
    scanf("%d",&elem);
    r=(r+1)%MAX;
    q[r]=elem;
    return;
}
}
void deque(){
if(f==-1 && r==-1){
    printf("EMPTY\n");
    return;
}
if(f==r){
    printf("The deleted element=%d\n",q[f]);
    f=-1;
    r=-1;
    return;
}
else{
    printf("The deleted element=%d\n",q[f]);
    f=(f+1)%MAX;
    return;
}
}
void display(){
int i;
if(f==-1 && r==-1){
    printf("EMPTY\n");
    return;
}
i=f;
printf("The elements are\n");
while(i!=r){
    printf("%d\t",q[i]);
    i=(i+1)%MAX;
}
printf("%d\n",q[r]);
return;
}