long long maxSumTrionic(int* nums, int numsSize) {
    #include <stdio.h>
    #include <limits.h>

    long long maxTrionicSubarraySum(int* nums, int numsSize){
        long long max_sum = LLONG_MIN;
        for (int l = 0; l < numsSize - 3; l++) {
            for (int r = l + 3; r < numsSize; r++) {
                for (int p = l + 1; p < r -1; p++) {
                    for (int q = p + 1; q < r; q++) {
                        int inc1 = 1, inc2 = 1;
                        long long current_sum = 0;
                        for (int i = l + 1; i <= p; i++) {
                            if (nums[i] <= nums[i-1]) {
                                inc1 = 0;
                                break;
                            }
                        }
                        for (int i = p + 1; i <= q; i++) {
                            if (nums[i] >= nums[i-1]) {
                                inc2 = 0;
                                break;
                            }
                        }
                        int inc3 = 1;
                        for (int i = q + 1; i <=r; i++) {
                            if (nums[i] <= nums[i-1]) {
                                inc3 = 0;
                                break;
                            }
                        }

                        if (inc1 && inc2 && inc3) {
                            for (int i = l; i <=r; i++) {
                                current_sum += nums[i];
                            }
                            max_sum = (max_sum > current_sum) ? max_sum : current_sum;
                        }
                    }
                }
            }
        }
        return max_sum;
    }
}