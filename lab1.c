#include<stdio.h>
int n,a[5],data,top;
void push(int item)
{
    if(top==n-1)
        printf("Stack is full(Stack overflow)");
    else{
        top+=1;
        a[top]=item;
    }

}
void pop()
{
    if(top==-1)
        printf("Stack is empty(Stack underflow)");
    else{
        int it=a[top];
        top=top-1;
        printf("\n popped item is %d.\n",it);
    }
}
void display()
{
    if(top==-1)
        printf("Stack is empty");
    else{
        for(int i=top;i>=0;i--)
            printf("%d\t",a[i]);
    }

}
void main()
{
    top=-1;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    while(top!=n-1)
    {
        printf("Enter the element to push:");
        scanf("%d",&data);
        push(data);
    }
    display();
    pop();
    display();
}
