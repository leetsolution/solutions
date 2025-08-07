class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 1;
        string word;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                if (word.rfind(searchWord, 0) == 0) {
                    return wordIndex;
                }
                wordIndex++;
                word = "";
            } else {
                word += sentence[i];
            }
        }
        if (word.rfind(searchWord, 0) == 0) {
            return wordIndex;
        }
        return -1;
    }
};