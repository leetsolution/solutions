class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxOdd = -1;
        int minEven = 101;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 0 && freq[i] > 0) {
                minEven = min(minEven, freq[i]);
            } else if (freq[i] % 2 != 0) {
                maxOdd = max(maxOdd, freq[i]);
            }
        }
        return maxOdd - minEven;
    }
};