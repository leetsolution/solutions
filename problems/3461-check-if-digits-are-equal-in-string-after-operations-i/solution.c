bool hasSameDigits(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    while (len > 2) {
        for (int i = 0; i < len - 1; i++) {
            s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
        }
        len--;
    }

    return s[0] == s[1];
}