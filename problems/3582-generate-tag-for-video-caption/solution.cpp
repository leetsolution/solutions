class Solution {
public:
    string generateTag(string caption) {
        string result = "#";
        string word;
        stringstream ss(caption);
        bool firstWord = true;

        while (ss >> word) {
            string processedWord = "";
            if (firstWord) {
                for (char c : word) {
                    if (isalpha(c)) {
                        processedWord += tolower(c);
                    }
                }
                firstWord = false;
            } else {
                if (!word.empty()) {
                    processedWord += toupper(word[0]);
                    for (int i = 1; i < word.length(); ++i) {
                        if (isalpha(word[i])) {
                            processedWord += tolower(word[i]);
                        }
                    }
                }
            }

            result += processedWord;
        }

        string filteredResult = "#";
        for (int i = 1; i < result.length(); ++i) {
            if (isalpha(result[i])) {
                filteredResult += result[i];
            }
        }

        if (filteredResult.length() > 100) {
            return filteredResult.substr(0, 101);
        }

        return filteredResult;
    }
};