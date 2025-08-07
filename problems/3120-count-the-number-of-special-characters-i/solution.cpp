class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        bool lowercase[26] = {false};
        bool uppercase[26] = {false};

        for (char c : word) {
            if (islower(c)) {
                lowercase[c - 'a'] = true;
            } else {
                uppercase[c - 'A'] = true;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (lowercase[i] && uppercase[i]) {
                count++;
            }
        }

        return count;
    }
};