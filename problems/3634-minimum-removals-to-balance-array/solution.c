int minRemoval(int* nums, int numsSize, int k) {
    #include <stdio.h>
    #include <stdlib.h>

    int minRemovals(int* nums, int numsSize, int k) {
        int n = numsSize;
        int minRemovals = n - 1; 
        for (int i = 0; i < (1 << n); ++i) {
            int subsetSize = 0;
            int* subset = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    subset[subsetSize++] = nums[j];
                }
            }

            if (subsetSize == 0) continue;

            int minVal = subset[0];
            int maxVal = subset[0];
            for (int j = 1; j < subsetSize; ++j) {
                minVal = (subset[j] < minVal) ? subset[j] : minVal;
                maxVal = (subset[j] > maxVal) ? subset[j] : maxVal;
            }

            if (maxVal <= (long long)minVal * k) {
                minRemovals = (minRemovals < (n - subsetSize)) ? minRemovals : (n - subsetSize);
            }
            free(subset);
        }
        return minRemovals;
    }
}