int maxSum(int* nums, int numsSize) {
    int max_sum = -1;
    int max_digits[10] = {0};

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int max_digit = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit > max_digit) {
                max_digit = digit;
            }
            num /= 10;
        }

        if (max_digits[max_digit] != 0) {
            int sum = nums[i] + max_digits[max_digit];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }

        num = nums[i];
        max_digit = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit > max_digit) {
                max_digit = digit;
            }
            num /= 10;
        }

        if (nums[i] > max_digits[max_digit]) {
            max_digits[max_digit] = nums[i];
        }
    }

    return max_sum;
}