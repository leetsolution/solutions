class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        vector<int> count(n + 1, 0);
        int start = rounds[0];
        int end = rounds.back();
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                count[i]++;
            }
        } else {
            for (int i = 1; i <= end; i++) {
                count[i]++;
            }
            for (int i = start; i <= n; i++) {
                count[i]++;
            }
        }
        int maxCount = 0;
        for (int i = 1; i <= n; i++) {
            maxCount = max(maxCount, count[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (count[i] == maxCount) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};