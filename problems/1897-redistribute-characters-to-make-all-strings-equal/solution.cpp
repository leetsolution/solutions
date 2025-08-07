class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        for (const string& word : words) {
            for (char c : word) {
                count[c - 'a']++;
            }
        }
        for (int c : count) {
            if (c % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};