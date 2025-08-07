int findMaxK(int* nums, int numsSize) {
    int maxK = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            for (int j = 0; j < numsSize; j++) {
                if (nums[j] == -nums[i]) {
                    if (nums[i] > maxK) {
                        maxK = nums[i];
                    }
                    break;
                }
            }
        }
    }
    return maxK;
}