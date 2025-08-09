/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int w = (int)sqrt(area);
    while (area % w != 0) {
        w--;
    }
    result[0] = area / w;
    result[1] = w;
    return result;
}