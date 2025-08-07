char * sortSentence(char * s){
    char **words = malloc(10 * sizeof(char *));
    char *word;
    int i = 0;
    word = strtok(s, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    qsort(words, i, sizeof(char *), [](const void *a, const void *b) {
        return (*(char **)a)[strlen(*(char **)a) - 1] - (*(char **)b)[strlen(*(char **)b) - 1];
    });
    char *result = malloc(200);
    result[0] = '\0';
    for (int j = 0; j < i; j++) {
        words[j][strlen(words[j]) - 1] = '\0';
        strcat(result, words[j]);
        if (j < i - 1) {
            strcat(result, " ");
        }
    }
    return result;
}