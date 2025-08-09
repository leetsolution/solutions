void moveZeroes(int* nums, int numsSize) {
    int nonzero_index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[nonzero_index++] = nums[i];
        }
    }
    for (int i = nonzero_index; i < numsSize; i++) {
        nums[i] = 0;
    }
}