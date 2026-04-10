// Recursive Insertion Sort
void insertionSort(int arr[], int n) {
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    // Insert last element at correct position
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}