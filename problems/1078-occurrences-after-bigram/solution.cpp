class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> words;
        string word;
        for (char c : text) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        for (int i = 0; i < words.size() - 2; ++i) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};