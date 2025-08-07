int longestMonotonicSubarray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int maxLen = 1;
    for (int i = 0; i < numsSize; ++i) {
        int increasingLen = 1;
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] > nums[j - 1]) {
                increasingLen++;
            } else {
                break;
            }
        }
        maxLen = (increasingLen > maxLen) ? increasingLen : maxLen;

        int decreasingLen = 1;
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] < nums[j - 1]) {
                decreasingLen++;
            } else {
                break;
            }
        }
        maxLen = (decreasingLen > maxLen) ? decreasingLen : maxLen;
    }

    return maxLen;
}