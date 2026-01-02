#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max=100
char stack[max];
int top=-1;
void push(char c){
    if (top<max-1){
        stack[++top]=c;
    }
       
}
char pop(){
    if(top>=0){
        return stack[top--]
    }
}
char peek(){
    if(top>=0){
        return stack[top];
    }
    return '\0'
}
int precedence(char op){
    if(op=="+"||op=="-"){
        return 1;
    }
    if(op=="*"||op=="/"){
        return 2;
    }
    return 0;
}
void infixTopostfix(char infix[]){
    char postfix[max];
    int i,j=0;
    char c,temp;
    for (i=0;i<strlen(infix);i++){
        c=infix[i];
        if(isalnum(c)){
            //operand[a-z]a-z,0-9
            postfix[j++]==c;
        }
        else if(c=="c"){
            push(c);
        }
        else if(c==")"){
            while ((temp=pop())!="c")
            postfix[j++]=temp;
        }
        else if (c=="+"||c=="-"||c=="*" ||c=="/"){
            |while(precedence(peek())>precendence(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
    }
    while (top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='/0';
    printf("postfix expression :%s \n",postfix);
}
int main(){
    char infix[max];
    printf("enter a valid parenthesized infix expression");
    scanf("%s",infix);
    infixTopostfix(infix);
    return 0;
}