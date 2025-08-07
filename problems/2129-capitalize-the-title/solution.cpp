class Solution {
public:
    string capitalizeTitle(string title) {
        string result = "";
        string word = "";
        for (int i = 0; i < title.length(); ++i) {
            if (title[i] == ' ') {
                if (word.length() <= 2) {
                    for (char &c : word) {
                        c = tolower(c);
                    }
                } else {
                    word[0] = toupper(word[0]);
                    for (int j = 1; j < word.length(); ++j) {
                        word[j] = tolower(word[j]);
                    }
                }
                result += word + " ";
                word = "";
            } else {
                word += title[i];
            }
        }

        if (word.length() <= 2) {
            for (char &c : word) {
                c = tolower(c);
            }
        } else {
            word[0] = toupper(word[0]);
            for (int j = 1; j < word.length(); ++j) {
                word[j] = tolower(word[j]);
            }
        }
        result += word;

        return result;
    }
};