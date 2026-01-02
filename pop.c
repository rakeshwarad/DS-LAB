#include <stdio.h>
int a[];
int top;

int pop() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        int item=a[top];
        top = top -1;
        a[top] = item;
        printf("Item %d removed from stack\n", item);
    }
}

int main() {
    int maxsize;
    printf("Enter the size of array ");
    scanf("%d", &maxsize);
    a[maxsize];
    top=maxsize-1;

    for(int i=0;i<maxsize;i++){
            printf("enter the elments of array");
            scanf("%d",&a[i]);
    }
    pop();


    return 0;
}

