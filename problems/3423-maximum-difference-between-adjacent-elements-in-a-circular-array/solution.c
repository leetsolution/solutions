int maxAdjacentDistance(int* nums, int numsSize) {
    int maxDiff = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int diff = abs(nums[i] - nums[i + 1]);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }
    int lastDiff = abs(nums[0] - nums[numsSize - 1]);
    if (lastDiff > maxDiff) {
        maxDiff = lastDiff;
    }
    return maxDiff;
}