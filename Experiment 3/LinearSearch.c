// C program to implement Linear Search
#include <stdio.h>

// Iterative Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   // return index
    }
    return -1;  // not found
}

int main() {
    int arr[] = {10, 25, 5, 40, 15};
    int n = 5, key = 40;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}