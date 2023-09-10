#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void removeNode() {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

int findTrump() {
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    if (head == NULL) {
        return -1; 
    }

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (fastPtr == NULL) {
        printf("The Trump is: %d %d\n", slowPtr->data, slowPtr->next->data);
    } else {
        printf("The Trump is: %d\n", slowPtr->data);
    }
    return 0; 
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char command[10];
    int value;

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "ADD") == 0) {
            fscanf(file, "%d", &value);
            insert(value);
        } else if (strcmp(command, "DELETE") == 0) {
            removeNode();
        }
    }

    fclose(file);

    int trump = findTrump();
    printf("Result is: %d\n", trump); 

    return 0;
}
