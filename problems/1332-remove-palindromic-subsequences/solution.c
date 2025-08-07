int removePalindromeSub(char* s) {
    int left = 0;
    int right = 0;
    while (s[right] != '\0') {
        right++;
    }
    right--;
    if (right < 0) return 0;
    while (left < right) {
        if (s[left] != s[right]) {
            return 2;
        }
        left++;
        right--;
    }
    return 1;
}