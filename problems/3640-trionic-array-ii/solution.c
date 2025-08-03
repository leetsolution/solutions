long long maxSumTrionic(int* nums, int numsSize) {
    #include <stdio.h>
    #include <limits.h>

    long long maxSubArraySum(int arr[], int size) {
        long long max_so_far = LLONG_MIN, max_ending_here = 0;
        for (int i = 0; i < size; i++) {
            max_ending_here = max_ending_here + arr[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }

    long long solve(int nums[], int n) {
        long long max_sum = LLONG_MIN;
        for (int l = 0; l < n - 3; l++) {
            for (int r = l + 3; r < n; r++) {
                for (int p = l + 1; p < r -1; p++) {
                    for (int q = p + 1; q < r; q++) {
                        int increasing1 = 1, decreasing = 1, increasing2 = 1;
                        for (int i = l + 1; i <= p; i++) {
                            if (nums[i] <= nums[i - 1]) {
                                increasing1 = 0;
                                break;
                            }
                        }
                        for (int i = p + 1; i <= q; i++) {
                            if (nums[i] >= nums[i - 1]) {
                                decreasing = 0;
                                break;
                            }
                        }
                        for (int i = q + 1; i <= r; i++) {
                            if (nums[i] <= nums[i - 1]) {
                                increasing2 = 0;
                                break;
                            }
                        }
                        if (increasing1 && decreasing && increasing2) {
                            long long current_sum = 0;
                            for (int i = l; i <= r; i++) {
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


    int main() {
        int nums[] = {0,-2,-1,-3,0,2,-1};
        int n = sizeof(nums) / sizeof(nums[0]);
        long long result = solve(nums, n);
        printf("%lld\n", result);
        return 0;
    }
}