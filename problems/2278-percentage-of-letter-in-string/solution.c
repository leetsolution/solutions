int percentageLetter(char* s, char letter) {
    int count = 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == letter) {
            count++;
        }
    }
    if (len == 0) {
        return 0;
    }
    return (count * 100) / len;
}