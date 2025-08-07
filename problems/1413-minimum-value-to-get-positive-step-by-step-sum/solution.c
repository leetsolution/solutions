int minStartValue(int* nums, int numsSize) {
    int minSum = 0;
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];
        if (currentSum < minSum) {
            minSum = currentSum;
        }
    }
    if (minSum >= 0) {
        return 1;
    } else {
        return 1 - minSum;
    }
}