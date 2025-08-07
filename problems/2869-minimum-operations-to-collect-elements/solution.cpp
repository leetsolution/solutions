class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int operations = 0;
        vector<bool> found(k + 1, false);
        for (int i = n - 1; i >= 0; --i) {
            operations++;
            if (nums[i] >= 1 && nums[i] <= k && !found[nums[i]]) {
                found[nums[i]] = true;
                count++;
            }
            if (count == k) {
                return operations;
            }
        }
        return operations;
    }
};