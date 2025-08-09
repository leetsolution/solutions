char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int plateCount[26] = {0};
    for (int i = 0; licensePlate[i]; i++) {
        char c = licensePlate[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z') plateCount[c - 'a']++;
    }
    char* shortestWord = NULL;
    int minLen = 16;
    for (int i = 0; i < wordsSize; i++) {
        int wordCount[26] = {0};
        for (int j = 0; words[i][j]; j++) {
            wordCount[words[i][j] - 'a']++;
        }
        bool complete = true;
        for (int j = 0; j < 26; j++) {
            if (wordCount[j] < plateCount[j]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            int len = strlen(words[i]);
            if (len < minLen) {
                minLen = len;
                shortestWord = words[i];
            }
        }
    }
    return shortestWord;
}