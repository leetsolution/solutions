int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int minLength = numsSize + 1;
    for (int i = 0; i < numsSize; i++) {
        int currentOr = 0;
        for (int j = i; j < numsSize; j++) {
            currentOr |= nums[j];
            if (currentOr >= k) {
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                }
                break;
            }
        }
    }
    if (minLength == numsSize + 1) {
        return -1;
    }
    return minLength;
}