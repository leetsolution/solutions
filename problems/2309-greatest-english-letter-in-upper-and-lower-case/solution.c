char* greatestLetter(char* s) {
    int lower[26] = {0};
    int upper[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower[s[i] - 'a'] = 1;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper[s[i] - 'A'] = 1;
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (lower[i] == 1 && upper[i] == 1) {
            char* result = (char*)malloc(sizeof(char) * 2);
            result[0] = (char)('A' + i);
            result[1] = '\0';
            return result;
        }
    }
    char* result = (char*)malloc(sizeof(char) * 1);
    result[0] = '\0';
    return result;
}