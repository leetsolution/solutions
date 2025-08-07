int subarraySum(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        int start = (i - nums[i] >= 0) ? i - nums[i] : 0;
        int subarraySum = 0;
        for (int j = start; j <= i; j++) {
            subarraySum += nums[j];
        }
        totalSum += subarraySum;
    }
    return totalSum;
}