char* removeTrailingZeros(char* num) {
    int len = 0;
    while (num[len] != '\0') {
        len++;
    }
    int i = len - 1;
    while (i >= 0 && num[i] == '0') {
        num[i] = '\0';
        i--;
    }
    return num;
}