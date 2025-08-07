int duplicateNumbersXOR(int* nums, int numsSize) {
    int counts[51] = {0};
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }

    for (int i = 1; i <= 50; i++) {
        if (counts[i] == 2) {
            result ^= i;
        }
    }

    return result;
}