class Solution {
public:
    string getEncryptedString(string s, int k) {
        string result = "";
        for (char c : s) {
            result += (char)(((c - 'a' + k) % 26) + 'a');
        }
        return result;
    }
};