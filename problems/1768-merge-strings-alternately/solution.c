char * mergeAlternately(char * word1, char * word2){
    int len1 = 0;
    while (word1[len1] != '\0') {
        len1++;
    }

    int len2 = 0;
    while (word2[len2] != '\0') {
        len2++;
    }

    int merged_len = len1 + len2;
    char *merged = (char *)malloc(sizeof(char) * (merged_len + 1));
    if (merged == NULL) return NULL;

    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }

    while (i < len1) {
        merged[k++] = word1[i++];
    }

    while (j < len2) {
        merged[k++] = word2[j++];
    }

    merged[k] = '\0';
    return merged;
}