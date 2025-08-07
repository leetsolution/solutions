int maximizeSum(int* nums, int numsSize, int k) {
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += maxVal;
        maxVal++;
    }
    return sum;
}