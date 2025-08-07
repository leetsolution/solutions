int divisorSubstrings(int num, int k) {
    char s[11];
    sprintf(s, "%d", num);
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i <= n - k; i++) {
        char sub[k + 1];
        strncpy(sub, s + i, k);
        sub[k] = '\0';
        int sub_num = atoi(sub);
        if (sub_num != 0 && num % sub_num == 0) {
            count++;
        }
    }
    return count;
}