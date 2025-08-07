char* makeSmallestPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left] < s[right]) {
                s[right] = s[left];
            } else {
                s[left] = s[right];
            }
        }
        left++;
        right--;
    }

    return s;
}