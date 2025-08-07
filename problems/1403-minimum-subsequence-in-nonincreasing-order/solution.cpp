class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        vector<int> subsequence;
        int subsequenceSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            subsequence.push_back(nums[i]);
            subsequenceSum += nums[i];
            if (subsequenceSum > totalSum - subsequenceSum) {
                return subsequence;
            }
        }
        return subsequence;
    }
};