class Solution {
public:
    string decodeMessage(string key, string message) {
        char mapping[26] = {0};
        char current_char = 'a';
        for (char c : key) {
            if (c != ' ' && mapping[c - 'a'] == 0) {
                mapping[c - 'a'] = current_char;
                current_char++;
            }
        }
        string decoded_message = "";
        for (char c : message) {
            if (c == ' ') {
                decoded_message += ' ';
            } else {
                decoded_message += mapping[c - 'a'];
            }
        }
        return decoded_message;
    }
};