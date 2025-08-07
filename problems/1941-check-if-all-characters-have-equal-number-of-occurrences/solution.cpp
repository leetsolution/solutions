class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int counts[26] = {0};
        for (char c : s) {
            counts[c - 'a']++;
        }
        int freq = 0;
        for (int count : counts) {
            if (count > 0) {
                if (freq == 0) {
                    freq = count;
                } else if (freq != count) {
                    return false;
                }
            }
        }
        return true;
    }
};