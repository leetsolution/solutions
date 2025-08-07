int largestInteger(int* nums, int numsSize, int k) {
    int counts[51] = {0};
    int n = numsSize;

    for (int i = 0; i <= n - k; i++) {
        int seen[51] = {0};
        for (int j = 0; j < k; j++) {
            if (nums[i + j] <= 50 && seen[nums[i + j]] == 0) {
                counts[nums[i + j]]++;
                seen[nums[i + j]] = 1;
            }
        }
    }

    int largest = -1;
    for (int i = 50; i >= 0; i--) {
        if (counts[i] == 1) {
            largest = i;
            break;
        }
    }

    return largest;
}