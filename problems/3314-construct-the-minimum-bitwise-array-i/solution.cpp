class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int x = num - 1;
            if ((x | (x + 1)) == num) {
                ans[i] = x;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};