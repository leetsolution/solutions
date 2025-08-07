int minOperations(int* nums, int numsSize, int k) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    int remainder = sum % k;
    if (remainder == 0) {
        return 0;
    }

    return remainder;
}