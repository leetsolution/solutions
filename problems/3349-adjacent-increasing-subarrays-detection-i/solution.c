bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    if (numsSize < 2 * k) {
        return false;
    }

    for (int a = 0; a <= numsSize - 2 * k; ++a) {
        int b = a + k;

        bool increasing_a = true;
        for (int i = a; i < a + k - 1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                increasing_a = false;
                break;
            }
        }

        bool increasing_b = true;
        for (int i = b; i < b + k - 1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                increasing_b = false;
                break;
            }
        }

        if (increasing_a && increasing_b) {
            return true;
        }
    }

    return false;
}