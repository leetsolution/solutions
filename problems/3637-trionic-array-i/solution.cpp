class Solution {
public:
    bool isTrionic(vector<int>& nums) {
    class Solution {
    public:
        bool isTrionic(vector<int>& nums) {
            int n = nums.size();
            for (int p = 1; p < n - 1; ++p) {
                for (int q = p + 1; q < n - 1; ++q) {
                    bool inc1 = true, dec2 = true, inc3 = true;
                    for (int i = 1; i <= p; ++i) {
                        if (nums[i] <= nums[i - 1]) {
                            inc1 = false;
                            break;
                        }
                    }
                    for (int i = p + 1; i <= q; ++i) {
                        if (nums[i] >= nums[i - 1]) {
                            dec2 = false;
                            break;
                        }
                    }
                    for (int i = q + 1; i < n; ++i) {
                        if (nums[i] <= nums[i - 1]) {
                            inc3 = false;
                            break;
                        }
                    }
                    if (inc1 && dec2 && inc3) return true;
                }
            }
            return false;
        }
    };
};