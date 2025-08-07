bool isValid(char* word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }

    if (len < 3) {
        return false;
    }

    bool hasVowel = false;
    bool hasConsonant = false;

    for (int i = 0; i < len; i++) {
        if (!((word[i] >= '0' && word[i] <= '9') ||
              (word[i] >= 'a' && word[i] <= 'z') ||
              (word[i] >= 'A' && word[i] <= 'Z'))) {
            return false;
        }

        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
            word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
            word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
            word[i] == 'U') {
            hasVowel = true;
        } else if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            hasConsonant = true;
        }
    }

    return hasVowel && hasConsonant;
}