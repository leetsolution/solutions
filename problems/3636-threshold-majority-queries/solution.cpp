class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
    #include <vector>
    #include <map>

    using namespace std;

    vector<int> majorityElementQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1], threshold = q[2];
            map<long long, int> freq;
            for (int i = l; i <= r; ++i) {
                freq[nums[i]]++;
            }
            int maxFreq = 0;
            long long maxElement = -1;
            for (auto const& [key, val] : freq) {
                if (val >= threshold) {
                    if (val > maxFreq) {
                        maxFreq = val;
                        maxElement = key;
                    } else if (val == maxFreq && key < maxElement) {
                        maxElement = key;
                    }
                }
            }
            ans.push_back(maxElement);
        }
        return ans;
    }
};