class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            if (num < 10) {
                result.push_back(num);
            } else {
                string s = to_string(num);
                for (char c : s) {
                    result.push_back(c - '0');
                }
            }
        }
        return result;
    }
};