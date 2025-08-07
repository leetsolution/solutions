int maximumValue(char** strs, int strsSize) {
    int maxVal = 0;
    for (int i = 0; i < strsSize; i++) {
        int val = 0;
        int isNumeric = 1;
        for (int j = 0; strs[i][j] != '\0'; j++) {
            if (strs[i][j] < '0' || strs[i][j] > '9') {
                isNumeric = 0;
                break;
            }
        }
        if (isNumeric) {
            for (int j = 0; strs[i][j] != '\0'; j++) {
                val = val * 10 + (strs[i][j] - '0');
            }
        } else {
            int len = 0;
            while (strs[i][len] != '\0') {
                len++;
            }
            val = len;
        }
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}