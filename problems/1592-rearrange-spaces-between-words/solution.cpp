class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        int words = 0;
        string word;
        vector<string> wordList;
        for (char c : text) {
            if (c == ' ') {
                spaces++;
                if (!word.empty()) {
                    wordList.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            wordList.push_back(word);
        }
        words = wordList.size();

        string result = "";
        if (words == 1) {
            result = wordList[0];
            result += string(spaces, ' ');
            return result;
        }

        int spacesBetween = spaces / (words - 1);
        int extraSpaces = spaces % (words - 1);

        for (int i = 0; i < words; ++i) {
            result += wordList[i];
            if (i < words - 1) {
                result += string(spacesBetween, ' ');
            }
        }
        result += string(extraSpaces, ' ');
        return result;
    }
};