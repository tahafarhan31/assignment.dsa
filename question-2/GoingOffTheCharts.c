#include <stdio.h>
#include <stdlib.h>

int findMaxConsecutiveExtendedWorkingHours(int n, int arr[]) {
    int maxConsecutiveDays = 0;
    int consecutiveDays = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 6) {
            consecutiveDays++;
            if (consecutiveDays > maxConsecutiveDays) {
                maxConsecutiveDays = consecutiveDays;
            }
        } else {
            consecutiveDays = 0;
        }
    }

    return maxConsecutiveDays;
}

void displayHistogram(int maxConsecutiveDays) {
    printf("Histogram:\n");
    for (int i = 1; i <= maxConsecutiveDays; i++) {
        printf("%2d |", i);
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Extended Working Hours Analyzer!\n");

    int option;
    printf("Choose an option:\n");
    printf("1. Use provided datasets\n");
    printf("2. Enter your own dataset\n");
    printf("Option: ");
    scanf("%d", &option);

    if (option == 1) {
        int numFiles = 5;

        for (int fileNum = 1; fileNum <= numFiles; fileNum++) {
            char fileName[100];
            sprintf(fileName, "data_%d.txt", fileNum);

            FILE *file = fopen(fileName, "r");
            if (file == NULL) {
                printf("Data file %s is not found or empty.\n", fileName);
                continue;
            }

            int n;
            fscanf(file, "%d", &n);

            int *arr = (int *)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Memory allocation error.\n");
                fclose(file);
                return 1;
            }

            printf("Reading data from %s...\n", fileName);
            for (int i = 0; i < n; i++) {
                fscanf(file, "%d,", &arr[i]);
            }

            fclose(file);

            int result = findMaxConsecutiveExtendedWorkingHours(n, arr);
            printf("Max consecutive extended working hours for %s: %d\n", fileName, result);
            displayHistogram(result);

            free(arr);
        }
    } else if (option == 2) {
        int n;
        printf("Enter the number of days in the dataset: ");
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation error.\n");
            return 1;
        }

        printf("Enter the working hours for each day separated by spaces: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int result = findMaxConsecutiveExtendedWorkingHours(n, arr);
        printf("Max consecutive extended working hours for your dataset: %d\n", result);
        displayHistogram(result);

        free(arr);
    } else {
        printf("Invalid option. Exiting...\n");
    }

    printf("\nThank you for using the Extended Working Hours Analyzer!\n");
    return 0;
}
