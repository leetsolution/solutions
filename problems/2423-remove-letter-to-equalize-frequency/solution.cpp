class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            string temp = word.substr(0, i) + word.substr(i + 1);
            vector<int> freq(26, 0);
            for (char c : temp) {
                freq[c - 'a']++;
            }
            vector<int> counts;
            for (int count : freq) {
                if (count > 0) {
                    counts.push_back(count);
                }
            }
            if (counts.empty()) continue;
            bool equal = true;
            for (int j = 1; j < counts.size(); ++j) {
                if (counts[j] != counts[0]) {
                    equal = false;
                    break;
                }
            }
            if (equal) return true;
        }
        return false;
    }
};