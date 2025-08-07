/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    char **result;
    int count = 0;
    int i, j, k;
    char *word;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *s = (char*)malloc((len1 + len2 + 2) * sizeof(char));
    strcpy(s, s1);
    strcat(s, " ");
    strcat(s, s2);

    char *token;
    char *saveptr;
    int freq[10000] = {0};
    token = strtok_r(s, " ", &saveptr);
    while (token != NULL) {
        int index = 0;
        int len = strlen(token);
        for (i = 0; i < len; i++) {
            index = index * 26 + (token[i] - 'a');
        }
        freq[index]++;
        token = strtok_r(NULL, " ", &saveptr);
    }

    for (i = 0; i < 10000; i++) {
        if (freq[i] == 1) {
            count++;
        }
    }
    result = (char **)malloc(count * sizeof(char *));
    *returnSize = count;
    k = 0;
    token = strtok_r(s1, " ", &saveptr);
    while (token != NULL) {
        int index = 0;
        int len = strlen(token);
        for (i = 0; i < len; i++) {
            index = index * 26 + (token[i] - 'a');
        }
        if (freq[index] == 1) {
            result[k] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(result[k], token);
            k++;
        }
        token = strtok_r(NULL, " ", &saveptr);
    }
    token = strtok_r(s2, " ", &saveptr);
    while (token != NULL) {
        int index = 0;
        int len = strlen(token);
        for (i = 0; i < len; i++) {
            index = index * 26 + (token[i] - 'a');
        }
        if (freq[index] == 1) {
            result[k] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(result[k], token);
            k++;
        }
        token = strtok_r(NULL, " ", &saveptr);
    }
    free(s);
    return result;
}