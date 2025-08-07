int maxSum(int* nums, int numsSize) {
    int seen[201] = {0};
    int currentSum = 0;
    int maxSum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        int num = nums[right];
        num += 100;

        while (seen[num] > 0) {
            int leftNum = nums[left];
            leftNum += 100;
            seen[leftNum]--;
            currentSum -= nums[left];
            left++;
        }

        seen[num]++;
        currentSum += nums[right];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}