class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (const string& word : words) {
            if (s.size() >= word.size() && s.substr(0, word.size()) == word) {
                count++;
            }
        }
        return count;
    }
};