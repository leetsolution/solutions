/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int sumAlice = 0;
    int sumBob = 0;
    for (int i = 0; i < aliceSizesSize; i++) {
        sumAlice += aliceSizes[i];
    }
    for (int i = 0; i < bobSizesSize; i++) {
        sumBob += bobSizes[i];
    }
    int diff = (sumBob - sumAlice) / 2;
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < aliceSizesSize; i++) {
        for (int j = 0; j < bobSizesSize; j++) {
            if (bobSizes[j] - aliceSizes[i] == diff) {
                ans[0] = aliceSizes[i];
                ans[1] = bobSizes[j];
                return ans;
            }
        }
    }
    return ans;
}