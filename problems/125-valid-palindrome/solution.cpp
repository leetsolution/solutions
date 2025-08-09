class Solution {
public:
    bool isPalindrome(string s) {
        string clean_s = "";
        for (char c : s) {
            if (isalnum(c)) {
                clean_s += tolower(c);
            }
        }

        int left = 0;
        int right = clean_s.length() - 1;

        while (left < right) {
            if (clean_s[left] != clean_s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};