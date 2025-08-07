char* freqAlphabets(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int resultIndex = 0;

    for (int i = 0; i < len; i++) {
        if (i + 2 < len && s[i + 2] == '#') {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            result[resultIndex++] = (char)(num + 'a' - 1);
            i += 2;
        } else {
            int num = s[i] - '0';
            result[resultIndex++] = (char)(num + 'a' - 1);
        }
    }

    result[resultIndex] = '\0';
    return result;
}