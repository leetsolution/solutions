bool hasSpecialSubstring(char* s, int k) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    if (k > n) {
        return false;
    }

    for (int i = 0; i <= n - k; i++) {
        char firstChar = s[i];
        bool allSame = true;
        for (int j = 1; j < k; j++) {
            if (s[i + j] != firstChar) {
                allSame = false;
                break;
            }
        }

        if (allSame) {
            bool beforeDifferent = true;
            if (i > 0) {
                if (s[i - 1] == firstChar) {
                    beforeDifferent = false;
                }
            }

            bool afterDifferent = true;
            if (i + k < n) {
                if (s[i + k] == firstChar) {
                    afterDifferent = false;
                }
            }

            if (beforeDifferent && afterDifferent) {
                return true;
            }
        }
    }

    return false;
}