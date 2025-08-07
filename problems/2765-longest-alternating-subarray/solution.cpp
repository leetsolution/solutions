class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxLen = -1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                bool alternating = true;
                if (nums[j] - nums[i] != 1) {
                    alternating = false;
                } else {
                    for (int k = i + 2; k <= j; ++k) {
                        if (nums[k] - nums[k - 1] != (k - i) % 2 == 0 ? -1 : 1) {
                            alternating = false;
                            break;
                        }
                    }
                }

                if (alternating) {
                    maxLen = std::max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};