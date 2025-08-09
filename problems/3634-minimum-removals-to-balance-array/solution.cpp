class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n - 1;
        for (int i = 0; i < n; i++) {
            int minVal = nums[i];
            int maxVal = minVal * k;
            int j = upper_bound(nums.begin(), nums.end(), maxVal) - nums.begin();
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};