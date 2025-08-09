class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> freq;
        for (char c : licensePlate) {
            c = tolower(c);
            if (isalpha(c)) {
                freq[c]++;
            }
        }
        string res = "";
        for (string word : words) {
            map<char, int> wordFreq;
            for (char c : word) {
                wordFreq[c]++;
            }
            bool complete = true;
            for (auto const& [key, val] : freq) {
                if (wordFreq.count(key) == 0 || wordFreq[key] < val) {
                    complete = false;
                    break;
                }
            }
            if (complete) {
                if (res == "" || word.length() < res.length()) {
                    res = word;
                }
            }
        }
        return res;
    }
};