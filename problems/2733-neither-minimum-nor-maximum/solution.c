int findNonMinOrMax(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return -1;
    }

    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != minVal && nums[i] != maxVal) {
            return nums[i];
        }
    }

    return -1;
}