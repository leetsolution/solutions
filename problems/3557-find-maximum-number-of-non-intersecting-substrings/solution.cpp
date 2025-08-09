class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            first[word[i] - 'a'] = min(first[word[i] - 'a'], i);
            last[word[i] - 'a'] = i;
        }
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (first[i] < last[i]) {
                int left = first[i];
                int right = last[i];
                int j = left;
                while (j <= right) {
                    if (first[word[j] - 'a'] < left) {
                        left = first[word[j] - 'a'];
                        j = left;
                    } else if (last[word[j] - 'a'] > right) {
                        right = last[word[j] - 'a'];
                    } else {
                        j++;
                    }
                }
                if (right - left + 1 >= 4) {
                    intervals.push_back({right, left});
                }
            }
        }
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int prevEnd = -1;
        for (auto interval : intervals) {
            int right = interval.first;
            int left = interval.second;
            if (left > prevEnd) {
                ans++;
                prevEnd = right;
            }
        }
        return ans;
    }
};