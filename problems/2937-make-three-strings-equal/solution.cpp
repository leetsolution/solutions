class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        int i = n1 - 1, j = n2 - 1, k = n3 - 1;
        int ans = 0;
        while (i >= 0 && j >= 0 && k >= 0) {
            if (s1[i] == s2[j] && s2[j] == s3[k]) {
                i--;
                j--;
                k--;
            } else {
                break;
            }
        }
        if (i == -1 && j == -1 && k == -1) {
            return n1 + n2 + n3 - 3 * (i + 1);
        } else {
            if (i != j || i != k || j != k) {
                return -1;
            } else {
                return n1 + n2 + n3 - 3 * (i + 1);
            }
        }
    }
};