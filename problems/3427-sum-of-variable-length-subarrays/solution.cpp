class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            long long currentSum = 0;
            for (int j = start; j <= i; ++j) {
                currentSum += nums[j];
            }
            totalSum += currentSum;
        }
        return totalSum;
    }
};