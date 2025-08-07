int similarPairs(char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            int word1_set[26] = {0};
            int word2_set[26] = {0};
            for (int k = 0; words[i][k] != '\0'; k++) {
                word1_set[words[i][k] - 'a'] = 1;
            }
            for (int k = 0; words[j][k] != '\0'; k++) {
                word2_set[words[j][k] - 'a'] = 1;
            }
            int similar = 1;
            for (int k = 0; k < 26; k++) {
                if (word1_set[k] != word2_set[k]) {
                    similar = 0;
                    break;
                }
            }
            if (similar) {
                count++;
            }
        }
    }
    return count;
}