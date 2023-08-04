#include <stdio.h>
#include <stdlib.h>

int CountBribes(int n, int arr[]) {
    int bribes = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] - (i + 1) > 2) {
            printf("Test Case Result: Too chaotic! Can't count bribes.\n");
            return -1;
        }
        for (int j = arr[i] - 2; j < i; j++) {
            if (j >= 0 && arr[j] > arr[i]) {
                bribes++;
            }
        }
    }
    return bribes;
}

int main() {
    printf("Welcome to the Bribe Counter!\n");
    int numTestCases;
    printf("Enter the number of test cases: ");
    scanf("%d", &numTestCases);

    int *results = (int *)malloc(numTestCases * sizeof(int));
    if (results == NULL) {
        printf("Memory allocation error for results array.\n");
        return 1;
    }

    for (int testCase = 1; testCase <= numTestCases; testCase++) {
        printf("\nTest Case %d\n", testCase);
        int n;
        printf("Enter the number of people in the queue: ");
        scanf("%d", &n);

        int *queue = (int *)malloc(n * sizeof(int));
        if (queue == NULL) {
            printf("Memory allocation error.\n");
            free(results);
            return 1;
        }

        printf("Enter the positions of people in the queue separated by spaces: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &queue[i]);
        }

        results[testCase - 1] = CountBribes(n, queue);

        free(queue);
    }

    printf("\nResults:\n");
    for (int testCase = 1; testCase <= numTestCases; testCase++) {
        if (results[testCase - 1] >= 0) {
            printf("Test Case %d - Number of bribes: %d\n", testCase, results[testCase - 1]);
        }
    }

    free(results);
    printf("\nThank you for using the Bribe Counter!\n");
    return 0;
}
