class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        vector<string> result;
        for (string word : words) {
            string lowerWord = "";
            for (char c : word) {
                lowerWord += tolower(c);
            }
            bool row1Word = true;
            bool row2Word = true;
            bool row3Word = true;
            for (char c : lowerWord) {
                if (row1.find(c) == string::npos) {
                    row1Word = false;
                }
                if (row2.find(c) == string::npos) {
                    row2Word = false;
                }
                if (row3.find(c) == string::npos) {
                    row3Word = false;
                }
            }
            if (row1Word || row2Word || row3Word) {
                result.push_back(word);
            }
        }
        return result;
    }
};