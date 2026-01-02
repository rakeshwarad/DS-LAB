#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Initialize hash table */
void initHashTable() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert key using linear probing */
void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        while (hashTable[(index + i) % m] != -1) {
            i++;
            if (i == m) {
                printf("Hash Table is Full. Cannot insert %d\n", key);
                return;
            }
        }
        hashTable[(index + i) % m] = key;
    }
}

/* Display hash table */
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main() {
    int n, key;

    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);

    initHashTable();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

