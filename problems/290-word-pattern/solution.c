bool wordPattern(char* pattern, char* s) {
    char *word;
    char *ptr = strtok_r(s, " ", &word);
    int pLen = strlen(pattern);
    char pMap[26][301] = {0};
    char wMap[301][26] = {0};
    int i = 0;
    while (ptr != NULL) {
        if (i >= pLen) return false;
        int pIndex = pattern[i] - 'a';
        int wLen = strlen(ptr);
        if (pMap[pIndex][0] == 0 && wMap[wLen][0] == 0) {
            strcpy(pMap[pIndex], ptr);
            wMap[wLen][0] = pattern[i];
        } else if (strcmp(pMap[pIndex], ptr) != 0 || wMap[wLen][0] != pattern[i]) {
            return false;
        }
        i++;
        ptr = strtok_r(NULL, " ", &word);
    }
    if (i != pLen) return false;
    return true;
}