#include<stdio.h>
#include<stdlib.h>
int a[10];
int n;
void display(){
    int i;
    if(n==0){
        printf("No elements\n");
        return;
    }
    printf("Elements are\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void insert(){
    int i,elem,pos;
    printf("Enter elememnt to be inserted\n");
    scanf("%d",&elem);
    printf("Enter position to be inserted\n");
    scanf("%d",&pos);
    for(i=n;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=elem;
    n=n+1;
}
void delete(){
    int pos,i;
    if(n==0){
        printf("No elements\n");
        return;
    }
    printf("Enter the position\n");
    scanf("%d",&pos);
    printf("Deleted element is=%d\n",a[pos]);
    for(i=pos;i<=n;i++){
        a[i]=a[i+1];
    }
    n=n-1;
}
void create(){
    int i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void main(){
int ch;
printf("Array Operations");
while(1){
    printf("1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.EXIT\n");
    printf("Enter ur choice\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:insert();
        break;
        case 4:delete();
        break;
        case 5:exit(0);
        default:printf("Enter a valid choice\n");
        break;
    }
}
}