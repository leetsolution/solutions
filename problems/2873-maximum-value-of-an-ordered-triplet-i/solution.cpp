class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_value = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long current_value = (long long)(nums[i] - nums[j]) * nums[k];
                    max_value = max(max_value, current_value);
                }
            }
        }
        return max_value;
    }
};