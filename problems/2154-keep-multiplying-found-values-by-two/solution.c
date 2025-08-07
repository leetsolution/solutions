int findFinalValue(int* nums, int numsSize, int original) {
    int found = 1;
    while (found) {
        found = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == original) {
                original *= 2;
                found = 1;
                break;
            }
        }
    }
    return original;
}