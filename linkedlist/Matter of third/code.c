#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode *next;
};

// Function to find the third last node in a linked list
struct ListNode *findThirdLast(struct ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return NULL;
    }

    struct ListNode *current = head;

    while (current->next->next->next != NULL) {
        current = current->next;
    }

    return current;
}

// Function to add a new node to the end of the linked list
void appendNode(struct ListNode **head, int value) {
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    FILE *filePointer = fopen("input.txt", "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int data;
    struct ListNode *listHead = NULL;

    while (fscanf(filePointer, "%d", &data) != EOF) {
        appendNode(&listHead, data);
    }

    struct ListNode *thirdLastNode = findThirdLast(listHead);

    if (thirdLastNode == NULL) {
        printf("The linked list is too short\n");
    } else {
        printf("The third last element of the input.txt file is %d\n", thirdLastNode->value);
    }

    fclose(filePointer); // Close the file when done

    // Free memory used by the linked list
    while (listHead != NULL) {
        struct ListNode *temp = listHead;
        listHead = listHead->next;
        free(temp);
    }

    return 0;
}
