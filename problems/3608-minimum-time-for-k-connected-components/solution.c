#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, time;
} Edge;

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->time - ((Edge*)b)->time;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unite(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (xroot == yroot)
        return;

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int minTime(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    Edge edgeList[edgesSize];
    for (int i = 0; i < edgesSize; i++) {
        edgeList[i].u = edges[i][0];
        edgeList[i].v = edges[i][1];
        edgeList[i].time = edges[i][2];
    }

    qsort(edgeList, edgesSize, sizeof(Edge), compareEdges);

    int parent[n];
    int rank[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int components = n;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i)
           components--;
    }
    components = n - components;

    if (components >= k) {
        return 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;

        if (find(parent, u) != find(parent, v)) {
            unite(parent, rank, u, v);
            components--;
        }

        if (components >= k) {
            return edgeList[i].time;
        }
    }

    return (edgesSize > 0) ? edgeList[edgesSize - 1].time : 0;
}