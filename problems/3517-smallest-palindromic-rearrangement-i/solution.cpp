class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        string half = "";
        char middle = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 == 1) {
                middle = (char)('a' + i);
            }
            for (int j = 0; j < counts[i] / 2; ++j) {
                half += (char)('a' + i);
            }
        }

        string result = half;
        if (middle != 0) {
            result += middle;
        }
        string reversed_half = half;
        reverse(reversed_half.begin(), reversed_half.end());
        result += reversed_half;

        return result;
    }
};