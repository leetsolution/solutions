bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    for (int i = len / 2; i >= 1; i--) {
        if (len % i == 0) {
            int repeat = len / i;
            bool match = true;
            for (int j = i; j < len; j++) {
                if (s[j] != s[j % i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    return false;
}