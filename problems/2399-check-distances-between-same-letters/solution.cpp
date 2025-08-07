class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.length(); ++i) {
            int charIndex = s[i] - 'a';
            for (int j = i + 1; j < s.length(); ++j) {
                if (s[j] == s[i]) {
                    if (j - i - 1 != distance[charIndex]) {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};