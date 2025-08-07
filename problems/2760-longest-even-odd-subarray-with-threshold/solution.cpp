class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int currentLen = 1;
                int j = i + 1;
                while (j < nums.size() && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2) {
                    currentLen++;
                    j++;
                }
                maxLen = std::max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};