int minXor(int* nums, int numsSize, int k) {
    int low = 0, high = 0;
    for (int i = 0; i < numsSize; i++) {
        high |= nums[i];
    }
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 1;
        int xor = 0;
        for (int i = 0; i < numsSize; i++) {
            xor ^= nums[i];
            if (xor > mid) {
                count++;
                xor = nums[i];
            } else if (xor == mid && i < numsSize - 1) {
                count++;
                xor = 0;
            }
        }
        if (count <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}