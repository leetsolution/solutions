/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    int *soldiers = (int*)malloc(matSize * sizeof(int));
    int *result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    for (int i = 0; i < matSize; i++) {
        int count = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                count++;
            } else {
                break;
            }
        }
        soldiers[i] = count;
    }

    for (int i = 0; i < k; i++) {
        int minSoldiers = 101;
        int minIndex = -1;
        for (int j = 0; j < matSize; j++) {
            if (soldiers[j] < minSoldiers) {
                minSoldiers = soldiers[j];
                minIndex = j;
            }
        }
        result[i] = minIndex;
        soldiers[minIndex] = 101;
    }

    return result;
}