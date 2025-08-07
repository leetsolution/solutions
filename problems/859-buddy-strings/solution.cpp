class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        if (s == goal) {
            unordered_set<char> chars;
            for (char c : s) chars.insert(c);
            return chars.size() < s.length();
        }
        vector<int> diff;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i]) diff.push_back(i);
        }
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};