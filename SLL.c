#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head=NULL;
node* end=NULL;

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
    printf("Operations on SLL\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at Beginning\n");
    printf("4.Insert at End\n");
    printf("5.Delete at Beginning\n");
    printf("6.Delete at End\n");
    printf("7.Find Length of SLL\n");
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
    tmp=(node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    return tmp;
}
void create(){
    int n,i;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        insert_end();
    }
}
void display(){
    node* tmp;
    tmp=head;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    while(tmp->next!=NULL){
        printf("%d\t",tmp->data);
        tmp=tmp->next;
    }
    printf("%d\t",tmp->data);
    printf("\n");
}
void find_len(){
    int len=0;
    node* tmp;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    tmp=head;
    len=1;
    if(head==end){
        printf("1\n");
        return;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next;
        len=len+1;
    }
    printf("Length=%d\n",len);
    return;
}
void insert_end(){
    node* tmp=getnode();
    if(head==NULL){
        head=tmp;
        end=tmp;
        return;
    }
    if(head==end){
        head->next=tmp;
        end=tmp;
        return;
    }
    else{
        end->next=tmp;
        end=tmp;
        return;
    }
}
void insert_beg(){
    node* tmp=getnode();
    if(head==NULL){
        head=tmp;
        end=tmp;
        return;
    }
    if(head==end){
        tmp->next=head;
        head=tmp;
        return;
    }
    else{
        tmp->next=head;
        head=tmp;
        return;
    }
}
void delete_beg(){
    if(head==NULL){
        printf("EMPTY\n");
        return;
    } 
    if(head==end){
        printf("Deleted element=%d\n",head->data);
        free(head);
        head=NULL;
        end=NULL;
        return;
    }
    else{
        printf("Deleted element=%d\n",head->data);
        node* tmp=head;
        head=head->next;
        free(tmp);
        return;
    }
}
void delete_end(){
    node* tmp;
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    if(head==end){
        printf("Deleted element=%d\n",head->data);
        free(head);
        head=NULL;
        end=NULL;
        return;
    }
    else{
        printf("Deleted element=%d\n",end->data);
        tmp=head;
        while(tmp->next!=end){
            tmp=tmp->next;
        }
        free(end);
        end=tmp;
        tmp->next=NULL;
        return;
    }
}