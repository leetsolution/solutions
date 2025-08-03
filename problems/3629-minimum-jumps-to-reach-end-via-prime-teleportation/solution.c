int minJumps(int* nums, int numsSize) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <limits.h>

    // Function to check if a number is prime
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
            dist[i] = INT_MAX;
        }
        dist[0] = 0;

        int* q = (int*)malloc(numsSize * sizeof(int));
        int head = 0, tail = 0;
        q[tail++] = 0;

        while (head < tail) {
            int curr = q[head++];
            if (curr == numsSize - 1) break;

            // Adjacent step
            if (curr + 1 < numsSize && dist[curr + 1] > dist[curr] + 1) {
                dist[curr + 1] = dist[curr] + 1;
                q[tail++] = curr + 1;
            }
            if (curr - 1 >= 0 && dist[curr - 1] > dist[curr] + 1) {
                dist[curr - 1] = dist[curr] + 1;
                q[tail++] = curr - 1;
            }

            // Prime teleportation
            if (isPrime(nums[curr])) {
                for (int i = 0; i < numsSize; i++) {
                    if (i != curr && nums[i] % nums[curr] == 0 && dist[i] > dist[curr] + 1) {
                        dist[i] = dist[curr] + 1;
                        q[tail++] = i;
                    }
                }
            }
        }

        free(q);
        int result = dist[numsSize - 1];
        free(dist);
        return result;
    }
}