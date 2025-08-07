class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_words = 0;
        for (const string& sentence : sentences) {
            int word_count = 0;
            for (char c : sentence) {
                if (c == ' ') {
                    word_count++;
                }
            }
            max_words = max(max_words, word_count + 1);
        }
        return max_words;
    }
};