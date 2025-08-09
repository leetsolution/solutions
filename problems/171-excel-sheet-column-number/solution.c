int titleToNumber(char* columnTitle) {
    int result = 0;
    for (int i = 0; columnTitle[i] != '\0'; i++) {
        int d = columnTitle[i] - 'A' + 1;
        result = result * 26 + d;
    }
    return result;
}