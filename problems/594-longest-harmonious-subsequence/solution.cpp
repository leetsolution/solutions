class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int maxLength = 0;
        for (auto const& [key, val] : count) {
            if (count.count(key + 1)) {
                maxLength = max(maxLength, val + count[key + 1]);
            }
        }
        return maxLength;
    }
};