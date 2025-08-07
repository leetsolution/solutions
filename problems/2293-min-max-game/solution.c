int minMaxGame(int* nums, int numsSize) {
    int n = numsSize;
    while (n > 1) {
        int newNums[n / 2];
        for (int i = 0; i < n / 2; i++) {
            if (i % 2 == 0) {
                newNums[i] = (nums[2 * i] < nums[2 * i + 1]) ? nums[2 * i] : nums[2 * i + 1];
            } else {
                newNums[i] = (nums[2 * i] > nums[2 * i + 1]) ? nums[2 * i] : nums[2 * i + 1];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            nums[i] = newNums[i];
        }
        n = n / 2;
    }
    return nums[0];
}