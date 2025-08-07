class Solution {
public:
    int countValidWords(string sentence) {
        int count = 0;
        string word;
        stringstream ss(sentence);
        while (ss >> word) {
            if (isValid(word)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isValid(string word) {
        int hyphenCount = 0;
        int punctuationCount = 0;

        for (int i = 0; i < word.length(); ++i) {
            if (isdigit(word[i])) {
                return false;
            }

            if (word[i] == '-') {
                hyphenCount++;
                if (hyphenCount > 1) {
                    return false;
                }
                if (i == 0 || i == word.length() - 1) {
                    return false;
                }
                if (!islower(word[i - 1]) || !islower(word[i + 1])) {
                    return false;
                }
            }

            if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                punctuationCount++;
                if (punctuationCount > 1) {
                    return false;
                }
                if (i != word.length() - 1) {
                    return false;
                }
            }

            if (!islower(word[i]) && word[i] != '-' && word[i] != '!' && word[i] != '.' && word[i] != ',')
            {
                return false;
            }
        }

        return true;
    }
};