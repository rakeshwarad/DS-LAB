#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int add_item;

    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;

        printf("Inserting element: ");
        scanf("%d", &add_item);

        rear = rear + 1;
        queue[rear] = add_item;
    }
}

void deleteq() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    else {
        printf("Deleted element is %d\n", queue[front]);
        front = front + 1;
    }
}

void display() {
    int i;

    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue is:\n");
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteq();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice. Try again\n");
        }
    }
}
