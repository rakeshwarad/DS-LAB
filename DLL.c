#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;

void createList() {
    struct Node *p;
    int x;

    printf("Enter elements (999 to stop): ");
    scanf("%d", &x);

    while (x != 999) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->info = x;
        p->prev = NULL;
        p->next = start;

        if (start != NULL)
            start->prev = p;

        start = p;
        scanf("%d", &x);
    }
}

void insertLeft(int key, int info) {
    struct Node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->info = info;
    p->prev = temp->prev;
    p->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = p;
    else
        start = p;

    temp->prev = p;
}

void deleteNode(int key) {
    struct Node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, info, key;

    while (1) {
        printf("\n1. Create List");
        printf("\n2. Insert Left");
        printf("\n3. Delete Node");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;

            case 2:
                scanf("%d %d", &key, &info);
                insertLeft(key, info);
                break;

            case 3:
                scanf("%d", &key);
                deleteNode(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
        }
    }
    return 0;
}
