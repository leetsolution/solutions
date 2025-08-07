/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize) {
    int start = rounds[0];
    int end = rounds[roundsSize - 1];
    int *result;
    int count = 0;
    if (start <= end) {
        count = end - start + 1;
        result = (int *)malloc(count * sizeof(int));
        for (int i = 0; i < count; i++) {
            result[i] = start + i;
        }
    } else {
        count = n - start + 1 + end;
        result = (int *)malloc(count * sizeof(int));
        for (int i = 0; i < n - start + 1; i++) {
            result[i] = start + i;
        }
        for (int i = 0; i < end; i++) {
            result[n - start + 1 + i] = i + 1;
        }
    }
    *returnSize = count;
    return result;
}