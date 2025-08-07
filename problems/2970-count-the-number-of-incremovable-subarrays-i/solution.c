int incremovableSubarrayCount(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int temp[50];
            int tempSize = 0;
            for (int k = 0; k < numsSize; k++) {
                if (k < i || k > j) {
                    temp[tempSize++] = nums[k];
                }
            }
            int increasing = 1;
            for (int k = 0; k < tempSize - 1; k++) {
                if (temp[k] >= temp[k + 1]) {
                    increasing = 0;
                    break;
                }
            }
            if (increasing) {
                count++;
            }
        }
    }
    return count;
}