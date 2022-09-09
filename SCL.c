#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
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
    printf("Operations on SCL\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at Beginning\n");
    printf("4.Insert at End\n");
    printf("5.Delete at Beginning\n");
    printf("6.Delete at End\n");
    printf("7.Find Length of SCL\n");
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
    }
void insert_beg(){
    node* temp=getnode();
    node* tmpp;
    if(head==NULL){
        head=temp;
        head->next=head;
        return;
    }
    else{
    tmpp=head;
    while(tmpp->next!=head){
        tmpp=tmpp->next;
    }
    temp->next=head;
    head=temp;
    tmpp->next=temp;
    return;
    }
    }
void insert_end(){
    node* temp=getnode();
    node* tmpp;
    if(head==NULL){
        head=temp;
        head->next=head;
        return;
    }
    else{
        tmpp=head;
        while(tmpp->next!=head){
            tmpp=tmpp->next;
        }
        tmpp->next=temp;
        temp->next=head;
        return;
    }
    }
void create(){
    int i,n;
    printf("Enter the no of elements to be inserted\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        insert_end();
    }
    return;
}
void delete_beg(){
    node* tmp;
    node* tmp1;
if(head==NULL){
    printf("EMPTY\n");
    return;
}
else if(head->next==head){
    printf("DELETED ELEMENT =%d\n",head->data);
    free(head);
    head=NULL;
    return;
}
else{
     printf("DELETED ELEMENT =%d\n",head->data);
     tmp=head;
     tmp1=head;
     while(tmp->next!=head){
         tmp=tmp->next;
     }
     tmp->next=head->next;
     head=head->next;
     free(tmp1);
     return;
}
}
void delete_end(){
    node *tmp1,*tmp2;
if(head==NULL){
    printf("EMPTY\n");
    return;
}
else if(head->next==head){
    printf("DELETED ELEMENT =%d\n",head->data);
    free(head);
    head=NULL;
    return;
}
else{
    tmp1=head;
    while(tmp1->next!=head){
        tmp1=tmp1->next;
    }
    tmp2=head;
    while(tmp2->next!=tmp1){
        tmp2=tmp2->next;
    }
    printf("DELETED ELEMENT =%d\n",tmp1->data);
    tmp2->next=head;
    free(tmp1);
    return;
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