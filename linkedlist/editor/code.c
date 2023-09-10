#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size;
};

void custom_push(struct Stack* stack, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int custom_pop(struct Stack* stack) {
    if (stack->size == 0) {
        return -1;
    }

    int data = stack->top->data;
    struct Node* top_node = stack->top;
    stack->top = stack->top->next;
    free(top_node);
    stack->size--;

    return data;
}

void custom_print_list(struct Node* custom_head) {
    struct Node* current = custom_head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void custom_add_number(struct Node **custom_head, int custom_number) {
    struct Node *custom_new_node = malloc(sizeof(struct Node));
    if (custom_new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    custom_new_node->data = custom_number;
    custom_new_node->next = NULL;

    if (*custom_head == NULL) {
        *custom_head = custom_new_node;
    } else {
        struct Node *custom_current = *custom_head;
        while (custom_current->next != NULL) {
            custom_current = custom_current->next;
        }
        custom_current->next = custom_new_node;
    }
}

void custom_delete_tail(struct Node **custom_head) {
    if (*custom_head == NULL) {
        return;
    } else if ((*custom_head)->next == NULL) {
        free(*custom_head);
        *custom_head = NULL;
    } else {
        struct Node *custom_current = *custom_head;
        while (custom_current->next->next != NULL) {
            custom_current = custom_current->next;
        }
        free(custom_current->next);
        custom_current->next = NULL;
    }
}

void custom_add_index(struct Node **custom_head, int custom_index, int custom_number) {
    if (custom_index < 0) {
        return;
    }

    struct Node *custom_new_node = malloc(sizeof(struct Node));
    if (custom_new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    custom_new_node->data = custom_number;

    if (custom_index == 0) {
        custom_new_node->next = *custom_head;
        *custom_head = custom_new_node;
    } else {
        struct Node *custom_current = *custom_head;
        int custom_i;
        for (custom_i = 0; custom_i < custom_index - 1 && custom_current != NULL; custom_i++) {
            custom_current = custom_current->next;
        }

        if (custom_current == NULL) {
            return; 
        }

        custom_new_node->next = custom_current->next;
        custom_current->next = custom_new_node;
    }
}

void custom_delete_index(struct Node **custom_head, int custom_index) {
    if (*custom_head == NULL || custom_index < 0) {
        return;
    }

    if (custom_index == 0) {
        struct Node *custom_temp = *custom_head;
        *custom_head = (*custom_head)->next;
        free(custom_temp);
    } else {
        struct Node *custom_current = *custom_head;
        int custom_i;
        for (custom_i = 0; custom_i < custom_index - 1 && custom_current->next != NULL; custom_i++) {
            custom_current = custom_current->next;
        }

        if (custom_current->next == NULL) {
            return; 
        }

        struct Node *custom_temp = custom_current->next;
        custom_current->next = custom_current->next->next;
        free(custom_temp);
    }
}


int main() {
    struct Node* custom_head = NULL;
    struct Stack custom_stack;
    custom_stack.top = NULL;
    custom_stack.size = 0;

    FILE* custom_fp = fopen("input.txt", "r");
    if (custom_fp == NULL) {
        printf("Error opening file\n");
        return 1;
    } else {
        printf("File opened successfully\n");
    }

    int custom_operation, custom_undo_index, custom_undo_number;
    char custom_line[100];
    while (fgets(custom_line, sizeof(custom_line), custom_fp)) {
        printf("Read line: %s", custom_line);
        int custom_command, custom_index, custom_number;
        sscanf(custom_line, "%d %d %d", &custom_command, &custom_index, &custom_number);

        switch (custom_command) {
            case 1:
                custom_operation = custom_pop(&custom_stack);
                custom_push(&custom_stack, 1);
                // Implement add_number function here
                break;
            case 2:
                custom_operation = custom_pop(&custom_stack);
                custom_push(&custom_stack, 2);
                // Implement delete_tail function here
                break;
            case 3:
                custom_push(&custom_stack, 3);
                // Implement add_index function here
                break;
            case 4:
                custom_push(&custom_stack, 4);
                // Implement delete_index function here
                break;
            case 5:
                custom_push(&custom_stack, 5);
                // Implement move_forward function here
                break;
            case 6:
                custom_push(&custom_stack, 6);
                // Implement move_backward function here
                break;
            case 7:
                custom_push(&custom_stack, 7);
                // Implement add_immediate function here
                break;
            case 8:
                custom_push(&custom_stack, 8);
                // Implement delete_immediate function here
                break;
            case 9:
                custom_print_list(custom_head);
                break;
            case 10:
                custom_push(&custom_stack, 10);
                // Implement update_index function here
                break;
            case 11:
                custom_push(&custom_stack, 11);
                // Implement update_immediate function here
                break;
            case 12:
                custom_push(&custom_stack, 12);
                // Implement shift function here
                break;
            case 13:
                switch (custom_operation) {
                  
                }
                break;
        }
    }

    fclose(custom_fp);

    // Cleanup and memory deallocation
    struct Node* current = custom_head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
