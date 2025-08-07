#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n_squared = gridSize * gridSize;
    int* counts = (int*)calloc(n_squared + 1, sizeof(int));
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            counts[grid[i][j]]++;
        }
    }
    
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int repeated = -1;
    int missing = -1;
    
    for (int i = 1; i <= n_squared; i++) {
        if (counts[i] == 2) {
            repeated = i;
        } else if (counts[i] == 0) {
            missing = i;
        }
    }
    
    ans[0] = repeated;
    ans[1] = missing;
    
    free(counts);
    
    return ans;
}