class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        if (max_val != n) {
            return false;
        }

        if (nums.size() != n + 1) {
            return false;
        }

        vector<int> counts(n + 1, 0);
        for (int num : nums) {
            if (num > n || num < 1) return false;
            counts[num]++;
        }

        for (int i = 1; i < n; ++i) {
            if (counts[i] != 1) {
                return false;
            }
        }

        if (counts[n] != 2) {
            return false;
        }

        return true;
    }
};