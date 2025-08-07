int countSubarrays(int* nums, int numsSize) {
    int count = 0;
    if (numsSize < 3) {
        return 0;
    }
    for (int i = 0; i <= numsSize - 3; i++) {
        if (nums[i] + nums[i + 2] == nums[i + 1] * 2) {
            count++;
        }
    }
    return count;
}