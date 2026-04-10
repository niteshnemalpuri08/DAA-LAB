// C program to implement Binary Search using recursion
#include <stdio.h>

// Recursive Binary Search Function
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;  // Element not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;  // Element found

    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);  // Search left

    else
        return binarySearch(arr, mid + 1, high, key); // Search right
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}