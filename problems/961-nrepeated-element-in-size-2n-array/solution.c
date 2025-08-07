int repeatedNTimes(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return nums[i];
        }
        if (i < numsSize - 2 && nums[i] == nums[i + 2]) {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}