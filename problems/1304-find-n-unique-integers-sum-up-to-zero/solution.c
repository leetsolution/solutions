/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        result[i] = i + 1;
        sum += result[i];
    }
    
    result[n - 1] = -sum;
    
    return result;
}