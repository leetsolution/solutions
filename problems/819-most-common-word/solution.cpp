class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> count;
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        string word;
        for (char c : paragraph) {
            if (isalnum(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (bannedWords.find(word) == bannedWords.end()) {
                    count[word]++;
                }
                word = "";
            }
        }
        if (!word.empty() && bannedWords.find(word) == bannedWords.end()) {
            count[word]++;
        }
        string mostFrequentWord;
        int maxCount = 0;
        for (auto const& [key, val] : count) {
            if (val > maxCount) {
                maxCount = val;
                mostFrequentWord = key;
            }
        }
        return mostFrequentWord;
    }
};