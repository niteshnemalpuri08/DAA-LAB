// Function to find minimum index
int minIndex(int arr[], int i, int j) {
    if (i == j)
        return i;

    int k = minIndex(arr, i + 1, j);

    return (arr[i] < arr[k]) ? i : k;
}

// Recursive Selection Sort
void selectionSort(int arr[], int n, int index) {
    if (index == n)
        return;

    int k = minIndex(arr, index, n - 1);

    // Swap
    if (k != index) {
        int temp = arr[k];
        arr[k] = arr[index];
        arr[index] = temp;
    }

    selectionSort(arr, n, index + 1);
}