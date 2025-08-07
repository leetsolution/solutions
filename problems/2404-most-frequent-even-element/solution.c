int mostFrequentEven(int* nums, int numsSize) {
    int counts[100001] = {0};
    int maxCount = 0;
    int result = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            counts[nums[i]]++;
            if (counts[nums[i]] > maxCount) {
                maxCount = counts[nums[i]];
                result = nums[i];
            } else if (counts[nums[i]] == maxCount && nums[i] < result) {
                result = nums[i];
            }
        }
    }

    return result;
}