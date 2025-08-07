class Solution {
public:
    bool digitCount(string num) {
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (num[j] - '0' == i) {
                    count++;
                }
            }
            if (count != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};