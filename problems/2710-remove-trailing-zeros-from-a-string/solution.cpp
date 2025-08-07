class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length();
        int i = n - 1;
        while (i >= 0 && num[i] == '0') {
            i--;
        }
        return num.substr(0, i + 1);
    }
};