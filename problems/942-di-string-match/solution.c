/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    *returnSize = n + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int low = 0;
    int high = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            result[i] = low++;
        } else {
            result[i] = high--;
        }
    }
    result[n] = low;
    return result;
}