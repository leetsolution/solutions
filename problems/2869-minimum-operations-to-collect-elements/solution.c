int minOperations(int* nums, int numsSize, int k) {
    int count = 0;
    int operations = 0;
    int collected[51] = {0};
    for (int i = numsSize - 1; i >= 0; i--) {
        operations++;
        if (nums[i] >= 1 && nums[i] <= k && collected[nums[i]] == 0) {
            collected[nums[i]] = 1;
            count++;
        }
        if (count == k) {
            return operations;
        }
    }
    return operations;
}