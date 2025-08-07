class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> counts(26, 0);
        for (char c : word) {
            counts[c - 'a']++;
        }
        sort(counts.rbegin(), counts.rend());
        int pushes = 0;
        for (int i = 0; i < 26; ++i) {
            int presses = 1 + i / 8;
            if (counts[i] > 0) {
                pushes += counts[i] * presses;
            } else {
                break;
            }
        }
        return pushes;
    }
};