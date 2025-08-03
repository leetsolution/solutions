class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
    #include <iostream>
    #include <vector>
    #include <map>

    using namespace std;

    vector<int> majorityElementQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int threshold = query[2];
            map<long long, int> freq;
            for (int i = l; i <= r; ++i) {
                freq[nums[i]]++;
            }
            int maxFreq = 0;
            long long maxElem = -1;
            for (auto const& [key, val] : freq) {
                if (val >= threshold) {
                    if (val > maxFreq) {
                        maxFreq = val;
                        maxElem = key;
                    } else if (val == maxFreq && key < maxElem) {
                        maxElem = key;
                    }
                }
            }
            ans.push_back(maxElem);
        }
        return ans;
    }
};