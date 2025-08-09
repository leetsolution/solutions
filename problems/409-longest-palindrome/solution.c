int longestPalindrome(char* s) {
    int counts[52] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            counts[s[i] - 'a']++;
        } else {
            counts[s[i] - 'A' + 26]++;
        }
    }
    int result = 0;
    int oddCount = 0;
    for (int i = 0; i < 52; i++) {
        result += counts[i] / 2 * 2;
        oddCount += counts[i] % 2;
    }
    if (oddCount > 0) {
        result++;
    }
    return result;
}