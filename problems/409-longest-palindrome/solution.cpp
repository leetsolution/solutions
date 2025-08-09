class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        int length = 0;
        int oddCount = 0;
        for (auto const& [key, val] : counts) {
            if (val % 2 == 0) {
                length += val;
            } else {
                length += val - 1;
                oddCount = 1;
            }
        }
        return length + oddCount;
    }
};