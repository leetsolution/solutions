class Solution {
public:
    char repeatedCharacter(string s) {
        bool seen[26] = {false};
        for (char c : s) {
            if (seen[c - 'a']) {
                return c;
            }
            seen[c - 'a'] = true;
        }
        return ' ';
    }
};