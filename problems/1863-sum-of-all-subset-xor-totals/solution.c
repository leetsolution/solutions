int subsetXORSum(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < (1 << numsSize); i++) {
        int xor_sum = 0;
        for (int j = 0; j < numsSize; j++) {
            if ((i >> j) & 1) {
                xor_sum ^= nums[j];
            }
        }
        sum += xor_sum;
    }
    return sum;
}