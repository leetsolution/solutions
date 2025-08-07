class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        long long min_sum = LLONG_MAX;
        bool found = false;

        for (int i = 0; i <= n - l; ++i) {
            for (int j = i + l - 1; j < n && j - i + 1 <= r; ++j) {
                long long current_sum = 0;
                for (int k = i; k <= j; ++k) {
                    current_sum += nums[k];
                }
                if (current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                    found = true;
                }
            }
        }

        if (!found) {
            return -1;
        }

        return (int)min_sum;
    }
};