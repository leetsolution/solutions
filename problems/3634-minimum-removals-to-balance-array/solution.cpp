class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int minimumRemovals(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 0;

        sort(nums.begin(), nums.end());
        int min_removed = n - 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                vector<int> subarray;
                for (int l = i; l <= j; ++l) {
                    subarray.push_back(nums[l]);
                }
                if (subarray.empty()) continue;

                int min_val = subarray[0];
                int max_val = subarray[subarray.size() - 1];

                if (max_val <= (long long)min_val * k) {
                    min_removed = min(min_removed, n - (j - i + 1));
                }
            }
        }
        return min_removed;
    }
};