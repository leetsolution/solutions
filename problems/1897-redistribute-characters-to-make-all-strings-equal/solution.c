bool makeEqual(char** words, int wordsSize) {
    int counts[26] = {0};
    int totalLength = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            counts[words[i][j] - 'a']++;
            totalLength++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] % wordsSize != 0) {
            return false;
        }
    }
    return true;
}