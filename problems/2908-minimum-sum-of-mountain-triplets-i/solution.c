int minimumSum(int* nums, int numsSize) {
    int min_sum = -1;

    for (int j = 1; j < numsSize - 1; j++) {
        int left_min = -1;
        for (int i = 0; i < j; i++) {
            if (nums[i] < nums[j]) {
                if (left_min == -1 || nums[i] < left_min) {
                    left_min = nums[i];
                }
            }
        }

        int right_min = -1;
        for (int k = j + 1; k < numsSize; k++) {
            if (nums[k] < nums[j]) {
                if (right_min == -1 || nums[k] < right_min) {
                    right_min = nums[k];
                }
            }
        }

        if (left_min != -1 && right_min != -1) {
            int current_sum = left_min + nums[j] + right_min;
            if (min_sum == -1 || current_sum < min_sum) {
                min_sum = current_sum;
            }
        }
    }

    return min_sum;
}