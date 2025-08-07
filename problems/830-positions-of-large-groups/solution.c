/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int count = 0;
    int start = 0;
    int** result = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || s[i] != s[i + 1]) {
            if (i - start + 1 >= 3) {
                result[(*returnSize)] = (int*)malloc(sizeof(int) * 2);
                result[(*returnSize)][0] = start;
                result[(*returnSize)][1] = i;
                (*returnColumnSizes)[(*returnSize)] = 2;
                (*returnSize)++;
            }
            start = i + 1;
        }
    }
    int** finalResult = (int**)malloc(sizeof(int*) * (*returnSize));
    int* finalColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        finalResult[i] = result[i];
        finalColumnSizes[i] = (*returnColumnSizes)[i];
    }
    free(result);
    free(*returnColumnSizes);
    *returnColumnSizes = finalColumnSizes;
    return finalResult;
}