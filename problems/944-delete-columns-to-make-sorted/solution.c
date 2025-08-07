int minDeletionSize(char** strs, int strsSize) {
    int n = strsSize;
    int len = strlen(strs[0]);
    int count = 0;

    for (int j = 0; j < len; j++) {
        for (int i = 1; i < n; i++) {
            if (strs[i][j] < strs[i - 1][j]) {
                count++;
                break;
            }
        }
    }

    return count;
}