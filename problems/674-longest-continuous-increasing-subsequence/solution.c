int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int maxLen = 1;
    int currLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currLen++;
        } else {
            maxLen = (maxLen > currLen) ? maxLen : currLen;
            currLen = 1;
        }
    }
    maxLen = (maxLen > currLen) ? maxLen : currLen;
    return maxLen;
}