class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        string vowels = "aeiou";
        for (int i = left; i <= right; ++i) {
            string word = words[i];
            if (vowels.find(word[0]) != string::npos && vowels.find(word.back()) != string::npos) {
                count++;
            }
        }
        return count;
    }
};