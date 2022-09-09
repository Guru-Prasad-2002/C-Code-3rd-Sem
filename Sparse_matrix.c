#include<stdio.h>
#include<stdlib.h>
void main(){
 int r=4,c=3;
 int a[r][c];
 int elem_no;
 int i,j; 
 int sp[12][3];
 printf("Enter the elements\n");
 for(i=0;i<r;i++){
     for(j=0;j<c;j++){
         scanf("%d",&a[i][j]);
     }
 }
 elem_no=1;
 for(i=0;i<r;i++){
     for(j=0;j<c;j++){
         if(a[i][j]!=0){
             sp[elem_no][0]=i;
             sp[elem_no][1]=j;
             sp[elem_no][3]=a[i][j];
             elem_no=elem_no+1;
         }
     }
 }
 printf("Sparse Matrix\n");
for(i=0;i<elem_no+1;i++){
    printf("%d\t%d\t%d\n",sp[i][0],sp[i][1],sp[i][2]);
}
return;
}