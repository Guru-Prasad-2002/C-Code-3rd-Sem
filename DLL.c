#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next,* prev;
}node;
node* head=NULL;
node* end=NULL;
node* getnode();
void insert_beg();
void delete_beg();
void insert_end();
void delete_end();
void find_len();
void display();
void create();
int main(){
int ch=0;
while(1){
    printf("Operations on DLL\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at Beginning\n");
    printf("4.Insert at End\n");
    printf("5.Delete at Beginning\n");
    printf("6.Delete at End\n");
    printf("7.Find Length of DLL\n");
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
    node* temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert_beg(){
    node* temp=getnode();
    if(head==NULL){ 
        head=temp;                  
        end=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
}
}
void insert_end(){
node* temp=getnode();
    if(head==NULL){ 
        head=temp;                  
        end=temp;
    }
    else{
        end->next=temp;
        temp->prev=end;
        end=temp;
    }
}
void create(){
int i;
int n;
printf("Enter the no of elements in DOUBLY LINEAR LINKED LIST\n");
scanf("%d",&n);
for(i=0;i<n;i++){
    insert_end();
}
return;
}
void display(){
node* temp=head;
if(head==NULL){
    printf("EMPTY\n");
    return;
}
else{
 while(temp->next!=NULL){
     printf("%d\t",temp->data);
     temp=temp->next;
 }
printf("%d\t",temp->data);
printf("\n");
}
}

void delete_beg(){
    node* temp;
 if(head==NULL){
 printf("EMPTY\n");
    return;
 }
 else if(head==end){
     printf("DELETED ELEMENT=%d\n",head->data);
     free(head);
     head=NULL;
     end=NULL;
     return;
 }
else{
  printf("DELETED ELEMENT=%d\n",head->data);
  temp=head;
  head=head->next;
  head->prev=NULL;
  free(temp);
  return;
}
}
void delete_end(){
    node* temp;
if(head==NULL){
 printf("EMPTY\n");
    return;
 }
 else if(head==end){
     printf("DELETED ELEMENT=%d\n",head->data);
     head=NULL;
     end=NULL;
     return;
 }
else{
  printf("DELETED ELEMENT=%d\n",end->data);
  temp=end;
  end=end->prev;
  end->next=NULL;
  free(temp);
  return;
}
}
void find_len(){
    node* temp=head;
    int count=0;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            count=count+1;
        }
    }
    printf("NO of ELEMENTS=%d\n",count+1);
    return;
}