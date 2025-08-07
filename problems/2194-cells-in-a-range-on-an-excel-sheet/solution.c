/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** cellsInRange(char* s, int* returnSize) {
    int c1 = s[0] - 'A';
    int r1 = s[1] - '0';
    int c2 = s[3] - 'A';
    int r2 = s[4] - '0';
    int size = (c2 - c1 + 1) * (r2 - r1 + 1);
    *returnSize = size;
    char** result = (char**)malloc(size * sizeof(char*));
    int k = 0;
    for (int i = c1; i <= c2; i++) {
        for (int j = r1; j <= r2; j++) {
            result[k] = (char*)malloc(3 * sizeof(char));
            result[k][0] = i + 'A';
            result[k][1] = j + '0';
            result[k][2] = '\0';
            k++;
        }
    }
    return result;
}