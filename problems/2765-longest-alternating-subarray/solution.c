int alternatingSubarray(int* nums, int numsSize) {
    int maxLen = -1;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            int len = j - i + 1;
            if (len > 1) {
                int alternating = 1;
                for (int k = i + 1; k <= j; k++) {
                    if (nums[k] - nums[k - 1] != ((k - i) % 2 == 1 ? 1 : -1)) {
                        alternating = 0;
                        break;
                    }
                }
                if (alternating) {
                    if (len > maxLen) {
                        maxLen = len;
                    }
                }
            }
        }
    }
    return maxLen;
}