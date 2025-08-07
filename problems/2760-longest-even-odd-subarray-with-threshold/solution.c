int longestAlternatingSubarray(int* nums, int numsSize, int threshold) {
    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0 && nums[i] <= threshold) {
            int currentLen = 1;
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                    currentLen++;
                } else {
                    break;
                }
            }
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }
    }
    return maxLen;
}