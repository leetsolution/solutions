int sumCounts(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            int distinctCount = 0;
            int distinct[101] = {0};
            for (int k = i; k <= j; k++) {
                if (distinct[nums[k]] == 0) {
                    distinctCount++;
                    distinct[nums[k]] = 1;
                }
            }
            sum += distinctCount * distinctCount;
        }
    }
    return sum;
}