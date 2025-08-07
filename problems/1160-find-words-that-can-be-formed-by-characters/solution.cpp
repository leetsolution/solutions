class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        vector<int> char_counts(26, 0);
        for (char c : chars) {
            char_counts[c - 'a']++;
        }

        for (string word : words) {
            vector<int> word_counts(26, 0);
            bool good = true;
            for (char c : word) {
                word_counts[c - 'a']++;
                if (word_counts[c - 'a'] > char_counts[c - 'a']) {
                    good = false;
                    break;
                }
            }
            if (good) {
                count += word.length();
            }
        }
        return count;
    }
};