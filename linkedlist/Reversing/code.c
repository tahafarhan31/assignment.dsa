#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Transaction {
    int id;
    int amount;
    struct Transaction* next;
};

struct Transaction* head = NULL;

void add_transaction(int transaction_id, int transaction_amount) {
    struct Transaction* new_transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    new_transaction->id = transaction_id;
    new_transaction->amount = transaction_amount;
    new_transaction->next = NULL;

    if (head == NULL) {
        head = new_transaction;
    } else {
        struct Transaction* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_transaction;
    }
}

void print_transaction_list() {
    struct Transaction* temp = head;
    while (temp != NULL) {
        printf("Transaction ID: %d, Amount: %d\n", temp->id, temp->amount);
        temp = temp->next;
    }
}

void delete_transaction(int transaction_id) {
    struct Transaction* temp = head;
    struct Transaction* prev = NULL;

    while (temp != NULL && temp->id != transaction_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        free(temp);
    }
}

int main() {
    FILE* file;
    int num_transactions, num_fraudulent_transactions;
    int transaction_id, transaction_amount;
    int* fraudulent_transaction_ids;
    int i, j;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(file, "%d %d", &num_transactions, &num_fraudulent_transactions);

    fraudulent_transaction_ids = (int*)malloc(sizeof(int) * num_fraudulent_transactions);

    for (i = 0; i < num_transactions; i++) {
        fscanf(file, "%d,%d", &transaction_id, &transaction_amount);
        add_transaction(transaction_id, transaction_amount);
    }

    for (j = 0; j < num_fraudulent_transactions; j++) {
        fscanf(file, "%d", &fraudulent_transaction_ids[j]);
        delete_transaction(fraudulent_transaction_ids[j]);
    }

    print_transaction_list();

    fclose(file);

    free(fraudulent_transaction_ids);

    return 0;
}
