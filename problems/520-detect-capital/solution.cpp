class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool allCaps = true;
        bool allLower = true;
        bool firstCapRestLower = true;

        for (int i = 0; i < n; ++i) {
            if (islower(word[i])) allCaps = false;
            if (isupper(word[i])) allLower = false;
            if (i > 0 && isupper(word[i])) firstCapRestLower = false;
        }

        if (allCaps || allLower || (isupper(word[0]) && firstCapRestLower)) return true;
        return false;
    }
};