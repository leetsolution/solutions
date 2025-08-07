class Solution {
public:
    int reverseDegree(string s) {
        int reverse_degree = 0;
        for (int i = 0; i < s.length(); ++i) {
            reverse_degree += (26 - (s[i] - 'a')) * (i + 1);
        }
        return reverse_degree;
    }
};