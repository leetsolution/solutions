class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (auto const& [key, val] : count) {
            if (val % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};