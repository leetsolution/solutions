class Solution {
public:
    string toGoatLatin(string sentence) {
        string res = "";
        string word = "";
        int count = 1;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ') {
                string temp = "";
                if (string("aeiouAEIOU").find(word[0]) != string::npos) {
                    temp = word + "ma";
                } else {
                    temp = word.substr(1) + word[0] + "ma";
                }
                for (int j = 0; j < count; j++) {
                    temp += 'a';
                }
                res += temp + " ";
                word = "";
                count++;
            } else {
                word += sentence[i];
            }
        }
        string temp = "";
        if (string("aeiouAEIOU").find(word[0]) != string::npos) {
            temp = word + "ma";
        } else {
            temp = word.substr(1) + word[0] + "ma";
        }
        for (int j = 0; j < count; j++) {
            temp += 'a';
        }
        res += temp;
        return res;
    }
};