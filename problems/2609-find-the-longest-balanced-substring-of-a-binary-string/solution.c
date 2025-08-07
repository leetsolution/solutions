int findTheLongestBalancedSubstring(char* s) {
    int max_len = 0;
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int zeros = 0;
            int ones = 0;
            int k;
            for (k = i; k < j; k++) {
                if (s[k] == '0') {
                    zeros++;
                } else if (s[k] == '1') {
                    ones++;
                } else {
                    break;
                }
            }

            if (k != j) continue;

            int balanced = 1;
            for (int l = i; l < i + zeros; l++) {
                if (s[l] != '0') {
                    balanced = 0;
                    break;
                }
            }
            if (!balanced) continue;

            for (int l = i + zeros; l < j; l++) {
                if (s[l] != '1') {
                    balanced = 0;
                    break;
                }
            }
            if (!balanced) continue;


            if (zeros == ones) {
                int len = j - i;
                if (len > max_len) {
                    max_len = len;
                }
            }
        }
    }

    return max_len;
}