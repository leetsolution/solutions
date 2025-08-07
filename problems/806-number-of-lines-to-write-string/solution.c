/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int lines = 1;
    int width = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int charWidth = widths[s[i] - 'a'];
        if (width + charWidth <= 100) {
            width += charWidth;
        } else {
            lines++;
            width = charWidth;
        }
    }
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = lines;
    result[1] = width;
    *returnSize = 2;
    return result;
}