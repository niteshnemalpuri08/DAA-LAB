// C program to implement Huffman Coding
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for Huffman Node
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char data, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Min Heap structure
struct MinHeap {
    int size;
    struct Node* arr[MAX];
};

// Swap two nodes
void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract minimum node
struct Node* extractMin(struct MinHeap* heap) {
    struct Node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}

// Insert node into heap
void insertHeap(struct MinHeap* heap, struct Node* node) {
    int i = heap->size;
    heap->size++;
    
    while (i && node->freq < heap->arr[(i - 1)/2]->freq) {
        heap->arr[i] = heap->arr[(i - 1)/2];
        i = (i - 1)/2;
    }
    heap->arr[i] = node;
}

// Build Huffman Tree
struct Node* buildHuffman(char data[], int freq[], int n) {
    struct MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < n; i++) {
        insertHeap(&heap, createNode(data[i], freq[i]));
    }

    while (heap.size > 1) {
        struct Node* left = extractMin(&heap);
        struct Node* right = extractMin(&heap);

        struct Node* newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        insertHeap(&heap, newNode);
    }

    return extractMin(&heap);
}

// Print Huffman Codes
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function
int main() {
    char data[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 1, 6, 3};
    int n = 4;

    struct Node* root = buildHuffman(data, freq, n);

    int arr[MAX], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}