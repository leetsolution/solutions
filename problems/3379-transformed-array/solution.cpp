class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                int steps = nums[i];
                int index = (i + steps) % n;
                result[i] = nums[index];
            } else if (nums[i] < 0) {
                int steps = abs(nums[i]);
                int index = ((i - steps) % n + n) % n;
                result[i] = nums[index];
            } else {
                result[i] = nums[i];
            }
        }
        return result;
    }
};