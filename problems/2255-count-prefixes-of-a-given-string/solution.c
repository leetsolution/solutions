int countPrefixes(char** words, int wordsSize, char* s) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        int j = 0;
        for (; j < len; j++) {
            if (words[i][j] != s[j]) {
                break;
            }
        }
        if (j == len) {
            count++;
        }
    }
    return count;
}