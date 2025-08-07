int countPartitions(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int leftSum = 0;
        for (int j = 0; j <= i; j++) {
            leftSum += nums[j];
        }
        int rightSum = 0;
        for (int j = i + 1; j < numsSize; j++) {
            rightSum += nums[j];
        }
        if ((leftSum - rightSum) % 2 == 0) {
            count++;
        }
    }
    return count;
}