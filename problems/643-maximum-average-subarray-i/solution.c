double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    double max_avg = sum / k;
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        max_avg = fmax(max_avg, sum / k);
    }
    return max_avg;
}