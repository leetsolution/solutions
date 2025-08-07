char* longestNiceSubstring(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    if (n == 0) {
        return "";
    }

    char* longest = "";
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int lower[26] = {0};
            int upper[26] = {0};
            int nice = 1;

            for (int k = i; k < j; k++) {
                if (s[k] >= 'a' && s[k] <= 'z') {
                    lower[s[k] - 'a'] = 1;
                } else {
                    upper[s[k] - 'A'] = 1;
                }
            }

            for (int k = 0; k < 26; k++) {
                if ((lower[k] == 1 && upper[k] == 0) || (lower[k] == 0 && upper[k] == 1)) {
                    nice = 0;
                    break;
                }
            }

            if (nice) {
                int len = j - i;
                if (len > maxLen) {
                    maxLen = len;
                    longest = s + i;
                }
            }
        }
    }

    if (maxLen == 0) {
        return "";
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    for (int i = 0; i < maxLen; i++) {
        result[i] = longest[i];
    }
    result[maxLen] = '\0';

    return result;
}