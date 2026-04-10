// C program to implement Kruskal's Algorithm for finding Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure for subset (Union-Find)
struct Subset {
    int parent;
    int rank;
};

// Function to find set of an element (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparator for qsort (sort edges by weight)
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // Store MST
    struct Subset subsets[V];

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    int e = 0; // index for result[]
    int i = 0; // index for sorted edges

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.u);
        int y = find(subsets, next.v);

        // If including this edge doesn't form a cycle
        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    // Print MST
    printf("Edges in Minimum Spanning Tree:\n");
    int total = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
        total += result[i].weight;
    }
    printf("Total cost of MST = %d\n", total);
}

// Main function
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}