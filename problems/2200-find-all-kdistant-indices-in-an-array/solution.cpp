class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        vector<int> keyIndices;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            bool found = false;
            for (int j : keyIndices) {
                if (abs(i - j) <= k) {
                    found = true;
                    break;
                }
            }
            if (found) {
                res.push_back(i);
            }
        }
        return res;
    }
};