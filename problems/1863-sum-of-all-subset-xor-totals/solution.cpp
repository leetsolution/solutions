class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int currentXOR = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    currentXOR ^= nums[j];
                }
            }
            totalSum += currentXOR;
        }
        return totalSum;
    }
};