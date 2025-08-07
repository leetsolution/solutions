class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        int maxLen = 1;
        for (int i = 0; i < n; ++i) {
            int increasingLen = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[j - 1]) {
                    increasingLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, increasingLen);

            int decreasingLen = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[j - 1]) {
                    decreasingLen++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, decreasingLen);
        }
        return maxLen;
    }
};