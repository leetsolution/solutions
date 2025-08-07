int maximumStrongPairXor(int* nums, int numsSize) {
    int maxXor = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                maxXor = max(maxXor, nums[i] ^ nums[j]);
            }
        }
    }
    return maxXor;
}