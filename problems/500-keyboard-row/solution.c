/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    char* row1 = "qwertyuiop";
    char* row2 = "asdfghjkl";
    char* row3 = "zxcvbnm";
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int row = 0;
        int found = 0;
        for (int j = 0; j < strlen(word); j++) {
            char c = tolower(word[j]);
            int inRow1 = strchr(row1, c) != NULL;
            int inRow2 = strchr(row2, c) != NULL;
            int inRow3 = strchr(row3, c) != NULL;
            if (inRow1) {
                if (row == 0) {
                    row = 1;
                } else if (row != 1) {
                    found = 1;
                    break;
                }
            } else if (inRow2) {
                if (row == 0) {
                    row = 2;
                } else if (row != 2) {
                    found = 1;
                    break;
                }
            } else if (inRow3) {
                if (row == 0) {
                    row = 3;
                } else if (row != 3) {
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            result[*returnSize] = strdup(word);
            (*returnSize)++;
        }
    }
    return result;
}