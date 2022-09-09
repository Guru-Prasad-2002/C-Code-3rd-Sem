#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct node* next;
}node;
node* front=NULL;
node* rear=NULL;

void enqueue();
void dequeue();
void display();
node* getnode(){
    node* tmp;
    tmp=(node*)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    return tmp;
}
void main(){
    int ch;
    printf("LINEAR QUEUE USING LINKED LIST\n");
    while(1){
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("Enter a VALID option\n");
            break;
        }
    }
} 
void enqueue(){
    node* newnode=getnode();
    if(front==NULL && rear==NULL){
        front=rear=newnode;
        return;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        return;
    }
}
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("EMPTY\n");
        return;
    }
    else if(front==rear){
        printf("DELETED ELEMENT=%d\n",front->data);
        free(front);
        front=rear=NULL;
        return;
    }
    else{
        printf("DELETED ELEMENT=%d\n",front->data);
        node* tmp=front;
        front=front->next;
        free(tmp);
        return;
    }

}
void display(){
    if(front==NULL && rear==NULL){
        printf("EMPTY\n");
        return;
    }
    node* tmp=front;
    printf("Elements are\n");
    while(tmp->next!=rear){
        printf("%d\t",tmp->data);
        tmp=tmp->next;
    }
    printf("%d\n",rear->data);
    return;
}


