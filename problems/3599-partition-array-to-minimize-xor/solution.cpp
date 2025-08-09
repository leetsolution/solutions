class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        for (int num : nums) {
            right = max(right, num);
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 1;
            int currentXor = 0;
            for (int num : nums) {
                currentXor ^= num;
                if (currentXor > mid) {
                    count++;
                    currentXor = num;
                }
            }
            if (count > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};