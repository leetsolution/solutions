bool isPossibleToSplit(int* nums, int numsSize) {
    int counts[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }

    int duplicates = 0;
    for (int i = 1; i <= 100; i++) {
        if (counts[i] > 1) {
            duplicates += counts[i] - 1;
        }
    }

    return duplicates <= numsSize / 2;
}