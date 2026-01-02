#include <stdio.h>
int a[];
int top;

void display() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        int maxsize;
        a[maxsize];
        for(int i=0;i<=top;i++){
            printf("%d is in the stack\n",a[i]);
        }
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
    display();


    return 0;
}
