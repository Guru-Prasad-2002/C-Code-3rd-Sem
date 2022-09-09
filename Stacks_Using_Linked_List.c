#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct node* next;
}node;
node* top=NULL;
node* getnode(){
    node* tmp;
    tmp=(node*)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    return tmp;
}
void push();
void pop();
void display();
void main(){
    int ch;
    printf("STACKS USING LINKED LIST\n");
    while(1){
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
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
void push(){
    node* newnode=getnode();
    if(top==NULL){
        top=newnode;
        return;
    }
    else{
        newnode->next=top;
        top=newnode;
        return;
    }
}   
void pop(){
    node* tmp;
    if(top==NULL){
        printf("EMPTY\n");
        return;
    }
    else if(top->next==NULL){
        printf("POPED ELEMENT=%d\n",top->data);
        tmp=top;
        top=NULL;
        free(tmp);
        return;
    }
    else{
        tmp=top;
        printf("POPED ELEMENT=%d\n",top->data);
        top=top->next;
        free(tmp);
        return;
    }
}
void display(){
    node* tmp;
    if(top==NULL){
        printf("EMPTY\n");
        return;
    }
    else{
        printf("Elements are\n");
        tmp=top;
        while(tmp->next!=NULL){
            printf("%d\t",tmp->data);
            tmp=tmp->next;
        }
        printf("%d\t",tmp->data);
        printf("\n");
        return;
    }
}