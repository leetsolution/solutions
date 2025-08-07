class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> counts;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                counts.push_back(freq[i]);
            }
        }

        int distinctChars = counts.size();
        if (distinctChars <= k) return 0;

        sort(counts.begin(), counts.end());

        int deletions = 0;
        for (int i = 0; i < distinctChars - k; i++) {
            deletions += counts[i];
        }

        return deletions;
    }
};