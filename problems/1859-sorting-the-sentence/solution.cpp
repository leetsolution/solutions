class Solution {
public:
    string sortSentence(string s) {
        string words[10];
        string word;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                words[s[i] - '0'] = word;
                word = "";
            } else if (s[i] == ' ') {
                continue;
            } else {
                word += s[i];
            }
        }
        words[s.back() - '0'] = word;
        string result = "";
        for (int i = 1; i <= 9; i++) {
            if (words[i].length() > 0) {
                result += words[i] + " ";
            }
        }
        result.pop_back();
        return result;
    }
};