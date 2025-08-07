class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int min_cost = INT_MAX;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                min_cost = min(min_cost, nums[0] + nums[i] + nums[j]);
            }
        }

        return min_cost;
    }
};