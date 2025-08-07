/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    int* ans = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    int prev = -10001;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) prev = i;
        ans[i] = i - prev;
    }
    prev = 10001;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) prev = i;
        ans[i] = (ans[i] > prev - i) ? prev - i : ans[i];
    }
    return ans;
}