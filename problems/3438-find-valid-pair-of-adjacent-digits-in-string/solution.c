char* findValidPair(char* s) {
    int counts[10] = {0};
    int len = 0;
    while (s[len] != '\0') {
        counts[s[len] - '0']++;
        len++;
    }

    for (int i = 0; i < len - 1; i++) {
        int firstDigit = s[i] - '0';
        int secondDigit = s[i + 1] - '0';

        if (firstDigit != secondDigit && counts[firstDigit] == firstDigit && counts[secondDigit] == secondDigit) {
            char* result = (char*)malloc(3 * sizeof(char));
            result[0] = s[i];
            result[1] = s[i + 1];
            result[2] = '\0';
            return result;
        }
    }

    return "";
}