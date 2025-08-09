class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        stringstream ss(s);
        string word;
        int i = 0;
        while (ss >> word) {
            if (i >= pattern.size()) return false;
            char c = pattern[i++];
            if (p2s.count(c) && p2s[c] != word) return false;
            if (s2p.count(word) && s2p[word] != c) return false;
            p2s[c] = word;
            s2p[word] = c;
        }
        return i == pattern.size();
    }
};