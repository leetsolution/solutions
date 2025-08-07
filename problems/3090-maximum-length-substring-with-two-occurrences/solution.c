int maximumLengthSubstring(char* s) {
    int maxLen = 0;
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int counts[26] = {0};
            int valid = 1;
            for (int k = i; k <= j; k++) {
                counts[s[k] - 'a']++;
            }

            for (int k = 0; k < 26; k++) {
                if (counts[k] > 2) {
                    valid = 0;
                    break;
                }
            }

            if (valid) {
                int currentLen = j - i + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
            }
        }
    }

    return maxLen;
}