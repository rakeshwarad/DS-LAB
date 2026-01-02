#include <stdio.h>
int a[]:
int top = -1;
int max;

void push(int item) {
    if (top == max - 1) {
        printf("The stack is full\n");
    } else {
        top++;
        a[top] = item;
        printf("Item %d pushed to stack\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        int item = a[top];
        top--;
        printf("Item %d removed from stack\n", item);
    }
}
void display(){
    if (top==-1){
        printf("stack is full");
    }
    else{
        for(int i=0;i<=top;i++){
                print("%d",a[i]);
    }
    }
}

int main() {
    printf("Enter the size of stack: ");
    scanf("%d", &max);
    int n, item;
    printf("Enter the number of items to store: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &item);
        push(item);
    }

    pop();
    display();// Free allocated memory
    return 0;
}
