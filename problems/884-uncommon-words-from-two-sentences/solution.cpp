class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        string word;
        stringstream ss1(s1);
        while (ss1 >> word) {
            count[word]++;
        }
        stringstream ss2(s2);
        while (ss2 >> word) {
            count[word]++;
        }
        vector<string> result;
        for (auto const& [key, val] : count) {
            if (val == 1) {
                result.push_back(key);
            }
        }
        return result;
    }
};