int findLHS(int* nums, int numsSize) {
    int i, j, maxLen = 0, count1, count2;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i != j) {
                if (abs(nums[i] - nums[j]) == 1) {
                    count1 = 0;
                    count2 = 0;
                    for (int k = 0; k < numsSize; k++) {
                        if (nums[k] == nums[i])
                            count1++;
                        if (nums[k] == nums[j])
                            count2++;
                    }
                    maxLen = maxLen > (count1 + count2) ? maxLen : (count1 + count2);
                }
            }
        }
    }
    return maxLen;
}