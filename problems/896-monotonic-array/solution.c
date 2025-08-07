bool isMonotonic(int* nums, int numsSize) {
    bool increasing = true;
    bool decreasing = true;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            increasing = false;
        }
        if (nums[i] > nums[i - 1]) {
            decreasing = false;
        }
    }
    return increasing || decreasing;
}