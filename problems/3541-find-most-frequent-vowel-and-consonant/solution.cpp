class Solution {
public:
    int maxFreqSum(string s) {
        int vowelFreq[5] = {0};
        int consonantFreq[26] = {0};
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        for (char c : s) {
            if (c == 'a') {
                vowelFreq[0]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[0]);
            } else if (c == 'e') {
                vowelFreq[1]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[1]);
            } else if (c == 'i') {
                vowelFreq[2]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[2]);
            } else if (c == 'o') {
                vowelFreq[3]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[3]);
            } else if (c == 'u') {
                vowelFreq[4]++;
                maxVowelFreq = max(maxVowelFreq, vowelFreq[4]);
            } else {
                consonantFreq[c - 'a']++;
                maxConsonantFreq = max(maxConsonantFreq, consonantFreq[c - 'a']);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};