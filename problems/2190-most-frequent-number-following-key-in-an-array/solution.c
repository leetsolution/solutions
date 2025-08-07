int mostFrequent(int* nums, int numsSize, int key) {
    int counts[1001] = {0};
    int maxCount = 0;
    int maxTarget = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == key) {
            counts[nums[i + 1]]++;
            if (counts[nums[i + 1]] > maxCount) {
                maxCount = counts[nums[i + 1]];
                maxTarget = nums[i + 1];
            }
        }
    }
    return maxTarget;
}