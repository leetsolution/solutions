int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int nums[n + 1];
    nums[0] = 0;
    nums[1] = 1;

    int max_val = 1;

    for (int i = 1; 2 * i <= n; i++) {
        if (2 * i <= n) {
            nums[2 * i] = nums[i];
            if (nums[2 * i] > max_val) {
                max_val = nums[2 * i];
            }
        }
        if (2 * i + 1 <= n) {
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            if (nums[2 * i + 1] > max_val) {
                max_val = nums[2 * i + 1];
            }
        }
    }

    return max_val;
}