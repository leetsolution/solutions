class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        for (int t = 0; t < n; ++t) {
            string temp = s;
            for (int i = 0; i <= t; ++i) {
                temp[order[i]] = '*';
            }
            long long count = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    bool valid = false;
                    for (int l = i; l <= j; ++l) {
                        if (temp[l] == '*') {
                            valid = true;
                            break;
                        }
                    }
                    if (valid) {
                        count++;
                    }
                }
            }
            if (count >= k) {
                return t;
            }
        }
        return -1;
    }
};