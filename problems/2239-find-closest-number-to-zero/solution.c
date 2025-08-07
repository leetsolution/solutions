int findClosestNumber(int* nums, int numsSize) {
    int closest = nums[0];
    int minDiff = abs(nums[0]);
    for (int i = 1; i < numsSize; i++) {
        int diff = abs(nums[i]);
        if (diff < minDiff) {
            minDiff = diff;
            closest = nums[i];
        } else if (diff == minDiff) {
            if (nums[i] > closest) {
                closest = nums[i];
            }
        }
    }
    return closest;
}