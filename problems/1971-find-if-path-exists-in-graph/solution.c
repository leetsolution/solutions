#include <stdbool.h>
#include <stdlib.h>

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) {
        return true;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int head = 0;
    int tail = 0;

    queue[tail++] = source;
    visited[source] = true;

    while (head < tail) {
        int current = queue[head++];

        for (int i = 0; i < edgesSize; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (u == current && !visited[v]) {
                if (v == destination) {
                    free(visited);
                    free(queue);
                    return true;
                }
                queue[tail++] = v;
                visited[v] = true;
            } else if (v == current && !visited[u]) {
                if (u == destination) {
                    free(visited);
                    free(queue);
                    return true;
                }
                queue[tail++] = u;
                visited[u] = true;
            }
        }
    }

    free(visited);
    free(queue);
    return false;
}