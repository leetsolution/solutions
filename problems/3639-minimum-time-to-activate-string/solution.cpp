class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
    #include <string>
    #include <vector>

    using namespace std;

    long long countValidSubstrings(const string& s) {
        long long count = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool valid = false;
                for (int k = i; k <= j; ++k) {
                    if (s[k] == '*') {
                        valid = true;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
            }
        }
        return count;
    }

    int minTimeToActivateString(string s, vector<int>& order, long long k) {
        int n = s.length();
        for (int t = 0; t < n; ++t) {
            s[order[t]] = '*';
            if (countValidSubstrings(s) >= k) {
                return t;
            }
        }
        return -1;
    }
};