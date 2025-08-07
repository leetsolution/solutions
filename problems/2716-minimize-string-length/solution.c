int minimizedStringLength(char* s) {
    int count[26] = {0};
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 0) {
            count[s[i] - 'a'] = 1;
            len++;
        }
    }
    return len;
}