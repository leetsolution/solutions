bool divideArray(int* nums, int numsSize) {
    int count[501] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for (int i = 1; i <= 500; i++) {
        if (count[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}