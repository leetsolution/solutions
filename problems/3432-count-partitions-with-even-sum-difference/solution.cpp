class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        long long leftSum = 0;
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if ((leftSum - rightSum) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};