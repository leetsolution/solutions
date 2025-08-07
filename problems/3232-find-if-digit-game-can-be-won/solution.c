bool canAliceWin(int* nums, int numsSize) {
    int single_digit_sum = 0;
    int double_digit_sum = 0;
    int bob_sum_single = 0;
    int bob_sum_double = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 10) {
            single_digit_sum += nums[i];
        } else {
            double_digit_sum += nums[i];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 10) {
            bob_sum_single += nums[i];
        }
        if (nums[i] < 10) {
            bob_sum_double += nums[i];
        }
    }

    if (single_digit_sum > bob_sum_single || double_digit_sum > bob_sum_double) {
        return true;
    }

    return false;
}