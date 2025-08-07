class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> counts(101, 0);
        for (int i = 0; i <= n - k; ++i) {
            vector<bool> seen(101, false);
            for (int j = i; j < i + k; ++j) {
                if (!seen[nums[j]]) {
                    counts[nums[j]]++;
                    seen[nums[j]] = true;
                }
            }
        }

        int largest = -1;
        for (int i = 100; i >= 0; --i) {
            if (counts[i] == 1) {
                largest = i;
                break;
            }
        }

        return largest;
    }
};