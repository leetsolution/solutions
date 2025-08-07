class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for (int a = 0; a <= nums.size() - 2 * k; ++a) {
            int b = a + k;
            bool increasingA = true;
            for (int i = a; i < a + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    increasingA = false;
                    break;
                }
            }
            if (!increasingA) continue;

            bool increasingB = true;
            for (int i = b; i < b + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    increasingB = false;
                    break;
                }
            }
            if (increasingB) return true;
        }
        return false;
    }
};