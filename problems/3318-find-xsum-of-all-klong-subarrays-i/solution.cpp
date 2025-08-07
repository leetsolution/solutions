class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> v;
            for (auto p : freq) {
                v.push_back({p.second, p.first});
            }
            sort(v.rbegin(), v.rend());
            long long sum = 0;
            for (int j = 0; j < min((int)v.size(), x); ++j) {
                int count = v[j].first;
                int num = v[j].second;
                for (int l = i; l < i + k; ++l) {
                    if (nums[l] == num && count > 0) {
                        sum += num;
                        count--;
                    }
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};