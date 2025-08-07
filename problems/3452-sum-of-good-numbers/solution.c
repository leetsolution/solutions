int sumOfGoodNumbers(int* nums, int numsSize, int k) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int isGood = 1;
        if (i - k >= 0 && nums[i] <= nums[i - k]) {
            isGood = 0;
        }
        if (i + k < numsSize && nums[i] <= nums[i + k]) {
            isGood = 0;
        }
        if (isGood) {
            sum += nums[i];
        }
    }
    return sum;
}