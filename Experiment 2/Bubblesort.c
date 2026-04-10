// C program to implement Bubble Sort using recursion
#include <stdio.h>

// Recursive Bubble Sort
void bubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursive call
    bubbleSort(arr, n - 1);
}