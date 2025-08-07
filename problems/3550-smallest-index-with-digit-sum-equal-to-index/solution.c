int smallestIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int num = nums[i];
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == i) {
            return i;
        }
    }
    return -1;
}