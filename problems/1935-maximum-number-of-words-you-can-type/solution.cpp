class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        string word;
        stringstream ss(text);
        while (ss >> word) {
            bool broken = false;
            for (char c : word) {
                if (brokenLetters.find(c) != string::npos) {
                    broken = true;
                    break;
                }
            }
            if (!broken) {
                count++;
            }
        }
        return count;
    }
};