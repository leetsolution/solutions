/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s);
    int numGroups = (len + k - 1) / k;
    char** result = (char**)malloc(numGroups * sizeof(char*));
    *returnSize = numGroups;

    for (int i = 0; i < numGroups; i++) {
        result[i] = (char*)malloc((k + 1) * sizeof(char));
        for (int j = 0; j < k; j++) {
            int index = i * k + j;
            if (index < len) {
                result[i][j] = s[index];
            } else {
                result[i][j] = fill;
            }
        }
        result[i][k] = '\0';
    }

    return result;
}