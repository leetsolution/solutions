int countKConstraintSubstrings(char* s, int k) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int zeros = 0;
            int ones = 0;
            for (int l = i; l <= j; l++) {
                if (s[l] == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            if (zeros <= k || ones <= k) {
                count++;
            }
        }
    }
    return count;
}