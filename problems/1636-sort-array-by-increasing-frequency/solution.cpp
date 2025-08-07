class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        map<int, vector<int>> freqMap;
        for (auto const& [key, val] : counts) {
            freqMap[val].push_back(key);
        }
        for (auto& it : freqMap) {
            sort(it.second.rbegin(), it.second.rend());
        }
        vector<int> result;
        for (auto const& [freq, nums] : freqMap) {
            for (int num : nums) {
                for (int i = 0; i < counts[num]; ++i) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};