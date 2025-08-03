class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int minimumRemovals(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minRemovals = n - 1; 

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (nums[j] <= nums[i] * k) {
                    minRemovals = min(minRemovals, n - (j - i + 1));
                } else {
                    break;
                }
            }
        }
        return minRemovals;
    }
};