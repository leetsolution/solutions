int specialArray(int* nums, int numsSize) {
    int count;
    for (int x = 0; x <= numsSize; x++) {
        count = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] >= x) {
                count++;
            }
        }
        if (count == x) {
            return x;
        }
    }
    return -1;
}