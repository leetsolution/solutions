char* maximumOddBinaryNumber(char* s) {
    int ones = 0;
    int len = 0;
    while (s[len] != '\0') {
        if (s[len] == '1') {
            ones++;
        }
        len++;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len - 1; i++) {
        if (ones > 1) {
            result[i] = '1';
            ones--;
        } else {
            result[i] = '0';
        }
    }
    result[len - 1] = '1';
    result[len] = '\0';

    return result;
}