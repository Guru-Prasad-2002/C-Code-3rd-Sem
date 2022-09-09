#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next,* prev;
}node;
node* head=NULL;

void create();
void find_len();
void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
node* getnode();

int main(){
int ch=0;
while(1){
    printf("Operations on DCL\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at Beginning\n");
    printf("4.Insert at End\n");
    printf("5.Delete at Beginning\n");
    printf("6.Delete at End\n");
    printf("7.Find Length of DCL\n");
    printf("8.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:insert_beg();
        break;
        case 4:insert_end();
        break;
        case 5:delete_beg();
        break;
        case 6:delete_end();
        break;
        case 7:find_len();
        break;
        case 8:exit(0);
        default:printf("Please Enter a VALID Option\n");
    }
}
return 0;
}
node* getnode(){
    node* tmp;
    tmp=(node*)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    tmp->prev=NULL;
    return tmp;
}
void insert_beg(){
    node* tmp=getnode();
    node* tmp1;
    if(head==NULL){
        head=tmp;
        head->next=head;
        head->prev=head;
        return;
    }
    else{
        tmp1=head->prev;
        tmp->next=head;
        tmp->prev=tmp1;
        tmp1->next=tmp;
        head=tmp;
        return;
    }
}
void insert_end(){
    node* tmp=getnode();
    node* tmp1;
    if(head==NULL){
        head=tmp;
        head->next=head;
        head->prev=head;
        return;
    }
    else{
        tmp1=head->prev;
        tmp1->next=tmp;
        tmp->prev=tmp1;
        tmp->next=head;
        head->prev=tmp;
        return;
    }
}
void create(){
int i,n;
printf("Enter the no of elements\n");
scanf("%d",&n);
for(i=0;i<n;i++){
    insert_end();
}
}
void display(){
    node* temp;
    temp=head;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\t",temp->data);
    printf("\n");
}

void delete_beg(){
    node* tmp;
if(head==NULL){
    printf("EMPTY\n");
    return;
}
if(head->next==head){
    printf("Deleted element =%d\n",head->data);
    free(head);
    head=NULL;
    return;
}
else{
    printf("Deleted element =%d\n",head->data);
    tmp=head->prev;
    node* tmp1=head;
    tmp->next=head->next;
    head=head->next;
    head->prev=tmp;
    free(tmp1);
    return;
}
}
void delete_end(){
    node* tmp;
    node* tmp1,*tmp2;
if(head==NULL){
    printf("EMPTY\n");
    return;
}
if(head->next==head){
    printf("Deleted element =%d\n",head->data);
    free(head);
    head=NULL;
    return;
}
else{
    printf("Deleted element =%d\n",head->prev->data);
    tmp1=head->prev;
    tmp2=tmp1->prev;
    tmp2->next=head;
    head->prev=tmp2;
    free(tmp1);
    return;
}
}
void find_len(){
    node * temp=head;
    int count=1;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
        count=count+1;
    }
    printf("NO of ELEMENTS in SCL=%d\n",count);
    return;
}