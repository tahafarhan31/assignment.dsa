#include <stdio.h>
#include <stdlib.h>

// Helper function to read an integer from the file
int readInteger(FILE *file, int *number) {
    if (fscanf(file, "%d", number) != 1) {
        return 0; // Error reading
    }
    return 1; // Success
}

// Function to print the elements of the array
void printArray(int arr[], size_t n) {
    printf("Array elements: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge two sorted arrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

// Merge Sort implementation
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int FixingCodeInProduction(int arr[], size_t n, int num) {
    // Sort the array using Merge Sort for better performance
    mergeSort(arr, 0, n - 1);

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            return mid; 
        } else if (arr[mid] < num) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int numFiles = 5; 
    int fileNum;
    for (fileNum = 1; fileNum <= numFiles; fileNum++) {
        char fileName[100]; 
        snprintf(fileName, sizeof(fileName), "input%d.txt", fileNum); 

        FILE *file;
        if (fopen_s(&file, fileName, "r") != 0) {
            printf("Error opening the file %s.\n", fileName);
            continue; 
        }

        int num, n;
        // Read the number of elements in the file
        if (!readInteger(file, &n) || n <= 0) {
            printf("Invalid number of elements in %s.\n", fileName);
            fclose(file);
            continue;
        }

        // Read the target number
        if (!readInteger(file, &num)) {
            printf("Error reading the target number from %s.\n", fileName);
            fclose(file);
            continue;
        }

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation error.\n");
            fclose(file);
            return 1;
        }

        for (size_t i = 0; i < n; i++) {
            if (i == n - 1) {
                if (fscanf(file, "%d", &arr[i]) != 1) {
                    printf("Error reading element %zu from %s.\n", i, fileName);
                    free(arr);
                    fclose(file);
                    return 1;
                }
            } else {
                if (fscanf(file, "%d,", &arr[i]) != 1) {
                    printf("Error reading element %zu from %s.\n", i, fileName);
                    free(arr);
                    fclose(file);
                    return 1;
                }
            }
        }

        fclose(file);

        printf("File %s:\n", fileName);
        printArray(arr, n);

        int result = FixingCodeInProduction(arr, n, num);
        if (result != -1) {
            printf("Index of the item %d: %d\n", num, result);
        } else {
            printf("Item %d not found in the array.\n", num);
        }

        free(arr);
    }

    return 0;
}
