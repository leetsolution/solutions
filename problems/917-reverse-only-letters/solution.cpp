class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) {
                left++;
            }
            while (left < right && !isalpha(s[right])) {
                right--;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};