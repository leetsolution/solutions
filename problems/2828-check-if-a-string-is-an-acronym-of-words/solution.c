bool isAcronym(char** words, int wordsSize, char* s) {
    int s_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }

    if (wordsSize != s_len) {
        return false;
    }

    for (int i = 0; i < wordsSize; i++) {
        if (words[i][0] != s[i]) {
            return false;
        }
    }

    return true;
}