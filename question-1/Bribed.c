#include <stdio.h>
#include <stdlib.h>

int BribedQueue(int n, int arr[]) {
    // Same logic as before, no changes needed.
}

int main() {
    int numFiles = 4;

    for (int fileNum = 1; fileNum <= numFiles; fileNum++) {
        char inputFileName[100];
        sprintf(inputFileName, "input%d.txt", fileNum);

        FILE *inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("The File %s is Empty.\n", inputFileName);
            continue;
        }

        int n;
        fscanf(inputFile, "%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation error.\n");
            fclose(inputFile);
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                fscanf(inputFile, "%d", &arr[i]);
            } else {
                fscanf(inputFile, "%d,", &arr[i]);
            }
        }

        fclose(inputFile);

        int result = BribedQueue(n, arr);

        free(arr);

        char outputFileName[100];
        sprintf(outputFileName, "output%d.txt", fileNum);
        FILE *outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Error opening output file %s.\n", outputFileName);
            return 1;
        }

        if (result >= 0) {
            fprintf(outputFile, "Number of bribes for input%d.txt: %d\n", fileNum, result);
            printf("Number of bribes for input%d.txt: %d\n", fileNum, result);
        } else {
            fprintf(outputFile, "Test Case Result: Too chaotic! Can't count bribes.\n");
            printf("Test Case Result: Too chaotic! Can't count bribes.\n");
        }

        fclose(outputFile);
    }

    return 0;
}
