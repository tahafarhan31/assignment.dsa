#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert_sorted(int array[], int size, int value) {
    int i = size - 1;
    while (i >= 0 && array[i] > value) {
        array[i + 1] = array[i];
        i--;
    }
    array[i + 1] = value;
}

double calculate_median(int array[], int size) {
    if (size % 2 == 0) {
        int mid1 = array[size / 2 - 1];
        int mid2 = array[size / 2];
        return (double)(mid1 + mid2) / 2.0;
    } else {
        return (double)array[size / 2];
    }
}

int main() {
    FILE* file_pointer;
    int value;
    int* values_array = NULL;
    int array_size = 0;

    file_pointer = fopen("input.txt", "r");
    if (file_pointer == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    while (fscanf(file_pointer, "%d", &value) != EOF) {
        array_size++;
        values_array = (int*)realloc(values_array, array_size * sizeof(int));
        if (values_array == NULL) {
            printf("Error allocating memory\n");
            return 1;
        }

        insert_sorted(values_array, array_size - 1, value);

        double median = calculate_median(values_array, array_size);
        printf("The Median of %d is: %.1f\n", value, median);
    }

    free(values_array);
    fclose(file_pointer);

    return 0;
}

