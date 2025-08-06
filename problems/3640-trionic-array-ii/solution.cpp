class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
    #include <iostream>
    #include <vector>
    #include <climits>

    using namespace std;

    long long maxTrionicSubarraySum(vector<long long>& nums) {
        long long n = nums.size();
        long long maxSum = LLONG_MIN;

        for (long long l = 0; l < n - 3; ++l) {
            for (long long r = l + 3; r < n; ++r) {
                for (long long p = l + 1; p < r - 1; ++p) {
                    for (long long q = p + 1; q < r; ++q) {
                        bool inc1 = true, dec = true, inc2 = true;
                        for (long long i = l + 1; i <= p; ++i) {
                            if (nums[i] <= nums[i - 1]) inc1 = false;
                        }
                        for (long long i = p + 1; i <= q; ++i) {
                            if (nums[i] >= nums[i - 1]) dec = false;
                        }
                        for (long long i = q + 1; i <= r; ++i) {
                            if (nums[i] <= nums[i - 1]) inc2 = false;
                        }

                        if (inc1 && dec && inc2) {
                            long long currentSum = 0;
                            for (long long i = l; i <= r; ++i) {
                                currentSum += nums[i];
                            }
                            maxSum = max(maxSum, currentSum);
                        }
                    }
                }
            }
        }
        return maxSum;
    }
};