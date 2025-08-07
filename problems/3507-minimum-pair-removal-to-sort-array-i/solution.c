int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    while (1) {
        int minSum = 2001;
        int minIndex = -1;
        int sorted = 1;
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                sorted = 0;
            }
            if (nums[i] + nums[i + 1] < minSum) {
                minSum = nums[i] + nums[i + 1];
                minIndex = i;
            }
        }

        if (sorted) {
            break;
        }

        if (minIndex == -1) break;

        nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
        for (int i = minIndex + 1; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        numsSize--;
        operations++;
    }
    return operations;
}