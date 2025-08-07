int maxScore(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    int max_score = 0;
    for (int i = 1; i < n; i++) {
        int left_zeros = 0;
        for (int j = 0; j < i; j++) {
            if (s[j] == '0') {
                left_zeros++;
            }
        }
        int right_ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                right_ones++;
            }
        }
        int score = left_zeros + right_ones;
        if (score > max_score) {
            max_score = score;
        }
    }
    return max_score;
}