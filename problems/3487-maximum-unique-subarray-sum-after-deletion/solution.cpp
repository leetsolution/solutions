class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;
        vector<int> seen(201, 0);

        for (int right = 0; right < n; ++right) {
            int val = nums[right] + 100;
            while (seen[val] > 0) {
                int leftVal = nums[left] + 100;
                currentSum -= nums[left];
                seen[leftVal]--;
                left++;
            }
            currentSum += nums[right];
            seen[val]++;
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};