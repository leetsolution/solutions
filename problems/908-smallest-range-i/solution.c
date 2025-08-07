int smallestRangeI(int* nums, int numsSize, int k) {
    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        minVal = fmin(minVal, nums[i]);
        maxVal = fmax(maxVal, nums[i]);
    }
    int range = maxVal - minVal;
    return (range <= 2 * k) ? 0 : range - 2 * k;
}