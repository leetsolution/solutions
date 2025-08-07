bool isGood(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    if (numsSize != maxVal + 1) {
        return false;
    }

    int count[201] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    if (count[maxVal] != 2) {
        return false;
    }

    for (int i = 1; i < maxVal; i++) {
        if (count[i] != 1) {
            return false;
        }
    }

    return true;
}