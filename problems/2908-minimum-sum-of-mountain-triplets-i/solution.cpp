class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int min_sum = INT_MAX;

        for (int j = 1; j < n - 1; ++j) {
            int i_val = INT_MAX;
            for (int i = 0; i < j; ++i) {
                if (nums[i] < nums[j]) {
                    i_val = std::min(i_val, nums[i]);
                }
            }

            int k_val = INT_MAX;
            for (int k = j + 1; k < n; ++k) {
                if (nums[k] < nums[j]) {
                    k_val = std::min(k_val, nums[k]);
                }
            }

            if (i_val != INT_MAX && k_val != INT_MAX) {
                min_sum = std::min(min_sum, i_val + nums[j] + k_val);
            }
        }

        if (min_sum == INT_MAX) {
            return -1;
        } else {
            return min_sum;
        }
    }
};