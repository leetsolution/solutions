class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxK = -1;
        std::unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }
        for (int num : nums) {
            if (num > 0 && numSet.count(-num)) {
                maxK = std::max(maxK, num);
            }
        }
        return maxK;
    }
};