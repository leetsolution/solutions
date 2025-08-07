/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize) {
    int capacity = 0;
    for (int i = 0; i < wordsSize; i++) {
        int len = 0;
        while (words[i][len] != '\0') {
            len++;
        }
        capacity += len;
    }

    char** result = (char**)malloc(capacity * sizeof(char*));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        int start = 0;
        int j = 0;
        while (words[i][j] != '\0') {
            if (words[i][j] == separator) {
                if (j > start) {
                    int len = j - start;
                    char* str = (char*)malloc((len + 1) * sizeof(char));
                    for (int k = 0; k < len; k++) {
                        str[k] = words[i][start + k];
                    }
                    str[len] = '\0';
                    result[*returnSize] = str;
                    (*returnSize)++;
                }
                start = j + 1;
            }
            j++;
        }
        if (j > start) {
            int len = j - start;
            char* str = (char*)malloc((len + 1) * sizeof(char));
            for (int k = 0; k < len; k++) {
                str[k] = words[i][start + k];
            }
            str[len] = '\0';
            result[*returnSize] = str;
            (*returnSize)++;
        }
    }

    return result;
}