bool canBeIncreasing(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            count++;
            if (count > 1) {
                return false;
            }
            if (i > 0 && i < numsSize - 2 && nums[i - 1] >= nums[i + 1] && nums[i] >= nums[i + 2]) {
                return false;
            }
        }
    }
    return true;
}