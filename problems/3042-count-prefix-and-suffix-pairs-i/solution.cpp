class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        if (str2.length() < str1.length()) {
            return false;
        }
        if (str2.substr(0, str1.length()) == str1 && str2.substr(str2.length() - str1.length()) == str1) {
            return true;
        }
        return false;
    }
};