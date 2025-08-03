class Solution {
public:
    long long numOfSubsequences(string s) {
    #include <string>
    #include <algorithm>

    using namespace std;

    long long countSubsequences(string s) {
        long long lCount = 0, lcCount = 0, lctCount = 0;
        for (char c : s) {
            if (c == 'L') {
                lCount++;
            } else if (c == 'C') {
                lcCount += lCount;
            } else if (c == 'T') {
                lctCount += lcCount;
            }
        }
        return lctCount;
    }

    long long maxSubsequences(string s) {
        long long maxCount = countSubsequences(s);
        for (int i = 0; i <= s.length(); ++i) {
            for (char c : {'L', 'C', 'T'}) {
                string temp = s;
                temp.insert(i, 1, c);
                maxCount = max(maxCount, countSubsequences(temp));
            }
        }
        return maxCount;
    }
};