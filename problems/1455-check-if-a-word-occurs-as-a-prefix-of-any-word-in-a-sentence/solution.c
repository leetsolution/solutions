int isPrefixOfWord(char* sentence, char* searchWord) {
    int index = 1;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        int len = strlen(searchWord);
        if (strlen(word) >= len && strncmp(word, searchWord, len) == 0) {
            return index;
        }
        index++;
        word = strtok(NULL, " ");
    }
    return -1;
}