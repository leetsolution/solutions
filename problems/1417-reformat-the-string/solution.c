char* reformat(char* s) {
    int digitCount = 0;
    int letterCount = 0;
    int len = 0;
    while (s[len] != '\0') {
        if (s[len] >= '0' && s[len] <= '9') {
            digitCount++;
        } else {
            letterCount++;
        }
        len++;
    }

    if (abs(digitCount - letterCount) > 1) {
        return "";
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[len] = '\0';

    int digitIndex = 0;
    int letterIndex = 0;
    char* digits = (char*)malloc((digitCount + 1) * sizeof(char));
    char* letters = (char*)malloc((letterCount + 1) * sizeof(char));
    int digitIdx = 0;
    int letterIdx = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digits[digitIdx++] = s[i];
        } else {
            letters[letterIdx++] = s[i];
        }
    }
    digits[digitIdx] = '\0';
    letters[letterIdx] = '\0';

    if (digitCount > letterCount) {
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                result[i] = digits[digitIndex++];
            } else {
                result[i] = letters[letterIndex++];
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                result[i] = letters[letterIndex++];
            } else {
                result[i] = digits[digitIndex++];
            }
        }
    }
    free(digits);
    free(letters);
    return result;
}