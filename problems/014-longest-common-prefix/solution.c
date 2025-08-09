char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    if (strsSize == 1) {
        return strs[0];
    }

    char* firstStr = strs[0];
    int len = strlen(firstStr);
    if (len == 0) {
        return "";
    }

    for (int i = 0; i < len; i++) {
        char currentChar = firstStr[i];
        for (int j = 1; j < strsSize; j++) {
            if (strlen(strs[j]) <= i || strs[j][i] != currentChar) {
                firstStr[i] = '\0';
                return firstStr;
            }
        }
    }

    return firstStr;
}