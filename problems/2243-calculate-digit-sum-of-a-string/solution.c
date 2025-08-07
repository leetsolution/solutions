char* digitSum(char* s, int k) {
    int len = strlen(s);
    while (len > k) {
        char* new_s = (char*)malloc(sizeof(char) * (len + 1));
        int new_len = 0;
        for (int i = 0; i < len; i += k) {
            int sum = 0;
            for (int j = i; j < len && j < i + k; j++) {
                sum += (s[j] - '0');
            }
            char sum_str[10];
            sprintf(sum_str, "%d", sum);
            int sum_len = strlen(sum_str);
            for (int j = 0; j < sum_len; j++) {
                new_s[new_len++] = sum_str[j];
            }
        }
        new_s[new_len] = '\0';
        free(s);
        s = new_s;
        len = new_len;
    }
    return s;
}