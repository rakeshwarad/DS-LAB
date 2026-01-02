#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *start=NULL;
void createList()
{
    int n,i,value;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        struct Node *temp,*newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}
void insertLeft() {
    int key, value;
    struct Node *temp, *newNode;
    printf("Enter value to insert left of: ");
    scanf("%d", &key);
    temp = start;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter new value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        start = newNode;
    temp->prev = newNode;
}
void deleteNode() {
    int value;
    struct Node *temp;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    temp = start;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted\n");
}
void display() {
    struct Node *temp;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createList(); break;
            case 2: insertLeft(); break;
            case 3: deleteNode(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
