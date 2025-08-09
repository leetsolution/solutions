class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> count;
        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]].push_back(i);
            freq[nums[i]]++;
        }
        int maxFreq = 0;
        for (auto it : freq) {
            maxFreq = max(maxFreq, it.second);
        }
        int minLen = nums.size();
        for (auto it : freq) {
            if (it.second == maxFreq) {
                minLen = min(minLen, count[it.first].back() - count[it.first].front() + 1);
            }
        }
        return minLen;
    }
};