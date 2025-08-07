class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        if (s.length() != 9) return false;
        vector<int> count(10, 0);
        for (char c : s) {
            if (c == '0') return false;
            count[c - '0']++;
        }
        for (int i = 1; i <= 9; i++) {
            if (count[i] != 1) return false;
        }
        return true;
    }
};