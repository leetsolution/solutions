#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int minJumps(int* nums, int numsSize) {
    int* dist = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dist[i] = -1;
    }
    dist[0] = 0;

    int* queue = (int*)malloc(numsSize * sizeof(int));
    int head = 0, tail = 0;
    queue[tail++] = 0;

    while (head < tail) {
        int u = queue[head++];

        if (u == numsSize - 1) {
            break;
        }

        int next_indices[2] = {u + 1, u - 1};
        for (int i = 0; i < 2; i++) {
            int v = next_indices[i];
            if (v >= 0 && v < numsSize && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[tail++] = v;
            }
        }

        if (isPrime(nums[u])) {
            for (int v = 0; v < numsSize; v++) {
                if (u != v && nums[v] % nums[u] == 0 && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    queue[tail++] = v;
                }
            }
        }
    }

    int result = dist[numsSize - 1];
    free(dist);
    free(queue);
    return result;
}