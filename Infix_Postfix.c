// LAB PRG 4
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 10

int s[N];
int top=-1;

void push(char);
char pop();
int pr(char);

void main(){
    char infx[N],pofx[N];
    char ch;
    char elem;
    int i=0,k=0;
    printf("Please enter the infix EXPRESSION\n");
    scanf("%s",infx);
    push('#');
    while((ch=infx[i++])!='\0'){
        if(ch=='(')
        push(ch);
        else if(isalnum(ch))
        pofx[k++]=ch;
        else if(ch==')'){
            while(s[top]!='(')
                pofx[k++]=pop();
            elem=pop();
        }
        else{
            while(pr(ch)<=pr(s[top]))
                pofx[k++]=pop();
            push(ch);
        }
        
    }
    while(s[top]!='#')
        pofx[k++]=pop();
    pofx[k]='\0';
    printf("POSTFIX EXPRESSION=%s\n",pofx);
    return;
}
void push(char elem){
    top=top+1;
    s[top]=elem;
    return;
}
char pop(){
    char elem;
    elem=s[top];
    top=top-1;
    return elem;
}
int pr(char elem){
    switch(elem){
        case '#':return 0;
        case '(':return 1;
        case '-':
        case '+':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':return 4;
    }
}
