class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int mid = n / 2;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < mid; i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                count1++;
            }
        }
        for (int i = mid; i < n; i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                count2++;
            }
        }
        return count1 == count2;
    }
};