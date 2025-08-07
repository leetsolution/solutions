int minimumOperations(int* nums, int numsSize) {
    int operations = 0;
    for (int i = 0; i < numsSize; i++) {
        int remainder = nums[i] % 3;
        if (remainder == 1) {
            operations += 1;
        } else if (remainder == 2) {
            operations += 1;
        }
    }
    return operations;
}