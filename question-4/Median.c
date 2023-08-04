#include <stdio.h>
#include <stdlib.h>

int SelectingTheMedian(int arr[], int n) {
    // Add your efficient median finding algorithm here
    // ...
    return medianValue;
}

int main() {
    int numFiles = 5;
    int fileNum;

    // Use dynamic array for file names
    char** fileNames = (char**)malloc(numFiles * sizeof(char*));
    if (fileNames == NULL) {
        printf("Memory allocation error for file names.\n");
        return 1;
    }

    for (fileNum = 1; fileNum <= numFiles; fileNum++) {
        // Allocate memory for each file name
        fileNames[fileNum - 1] = (char*)malloc(100 * sizeof(char));
        if (fileNames[fileNum - 1] == NULL) {
            printf("Memory allocation error for file name.\n");
            continue;
        }
        snprintf(fileNames[fileNum - 1], 100, "input%d.txt", fileNum);

        FILE *file = fopen(fileNames[fileNum - 1], "r");
        if (file == NULL) {
            printf("Error opening the file %s.\n", fileNames[fileNum - 1]);
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

        int i;
        for (i = 0; i < n; i++) {
            if (i == n - 1) {
                fscanf(file, "%d", &arr[i]);
            } else {
                fscanf(file, "%d,", &arr[i]);
            }
        }

        fclose(file);

        int result = SelectingTheMedian(arr, n);
        printf("Median value for %s: %d\n", fileNames[fileNum - 1], result);

        free(arr);
    }

    // Free memory for file names
    for (fileNum = 0; fileNum < numFiles; fileNum++) {
        free(fileNames[fileNum]);
    }
    free(fileNames);

    return 0;
}
