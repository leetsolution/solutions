int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int minSum = -1;
    for (int i = 0; i <= numsSize - l; i++) {
        for (int j = l; j <= r && i + j <= numsSize; j++) {
            int currentSum = 0;
            for (int k = i; k < i + j; k++) {
                currentSum += nums[k];
            }
            if (currentSum > 0) {
                if (minSum == -1 || currentSum < minSum) {
                    minSum = currentSum;
                }
            }
        }
    }
    return minSum;
}