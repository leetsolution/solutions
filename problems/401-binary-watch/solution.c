/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char **result = malloc(1000 * sizeof(char*));
    *returnSize = 0;
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            int count = 0;
            int temp = h;
            while (temp > 0) {
                count += temp & 1;
                temp >>= 1;
            }
            temp = m;
            while (temp > 0) {
                count += temp & 1;
                temp >>= 1;
            }
            if (count == turnedOn) {
                char buf[10];
                sprintf(buf, "%d:%02d", h, m);
                result[*returnSize] = malloc(strlen(buf) + 1);
                strcpy(result[*returnSize], buf);
                (*returnSize)++;
            }
        }
    }
    return result;
}