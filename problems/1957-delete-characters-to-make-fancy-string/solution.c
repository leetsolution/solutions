char* makeFancyString(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (len <= 2) {
        return s;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int resultIndex = 0;

    for (int i = 0; i < len; i++) {
        if (resultIndex >= 2 && result[resultIndex - 1] == s[i] && result[resultIndex - 2] == s[i]) {
            continue;
        } else {
            result[resultIndex++] = s[i];
        }
    }

    result[resultIndex] = '\0';
    return result;
}