#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int to;
    int start;
    int end;
} Edge;

int minTime(int n, int** edges, int edgesSize, int* edgesColSize) {
    Edge** adj = (Edge**)malloc(n * sizeof(Edge*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    int* adjCapacity = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adjCapacity[i] = 2;
        adj[i] = (Edge*)malloc(adjCapacity[i] * sizeof(Edge));
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int start = edges[i][2];
        int end = edges[i][3];

        if (adjSize[u] == adjCapacity[u]) {
            adjCapacity[u] *= 2;
            adj[u] = (Edge*)realloc(adj[u], adjCapacity[u] * sizeof(Edge));
        }

        adj[u][adjSize[u]].to = v;
        adj[u][adjSize[u]].start = start;
        adj[u][adjSize[u]].end = end;
        adjSize[u]++;
    }

    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    int* visited = (int*)calloc(n, sizeof(int));

    for (int count = 0; count < n; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || (dist[v] != INT_MAX && dist[v] < dist[u]))) {
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].to;
            int start = adj[u][i].start;
            int end = adj[u][i].end;

            if (dist[u] <= end && dist[u] >= start)
            {
                if (dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                }
            }
            else if (dist[u] < start)
            {
                if (dist[v] > start + 1)
                {
                    dist[v] = start + 1;
                }
            }
           
        }
    }
    
    int result = (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
    

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(adjCapacity);
    free(dist);
    free(visited);

    return result;
}