class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated_word = word;
        while (sequence.find(repeated_word) != string::npos) {
            k++;
            repeated_word += word;
        }
        return k;
    }
};