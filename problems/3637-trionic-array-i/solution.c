bool isTrionic(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }

    for (int p = 1; p < numsSize - 1; p++) {
        for (int q = p + 1; q < numsSize; q++) {
            bool increasing1 = true;
            for (int i = 0; i < p; i++) {
                if (nums[i] >= nums[i + 1]) {
                    increasing1 = false;
                    break;
                }
            }

            bool decreasing = true;
            for (int i = p; i < q; i++) {
                if (nums[i] <= nums[i + 1]) {
                    decreasing = false;
                    break;
                }
            }

            bool increasing2 = true;
            for (int i = q; i < numsSize - 1; i++) {
                if (nums[i] >= nums[i + 1]) {
                    increasing2 = false;
                    break;
                }
            }

            if (increasing1 && decreasing && increasing2) {
                return true;
            }
        }
    }

    return false;
}