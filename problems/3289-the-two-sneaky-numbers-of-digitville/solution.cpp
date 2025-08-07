class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<int> result;
        for (auto const& [key, val] : count) {
            if (val == 2) {
                result.push_back(key);
            }
        }
        return result;
    }
};