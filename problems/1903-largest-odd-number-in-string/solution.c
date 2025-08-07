char* largestOddNumber(char* num) {
    int n = strlen(num);
    for (int i = n - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 != 0) {
            char* result = (char*)malloc((i + 1) * sizeof(char));
            strncpy(result, num, i + 1);
            result[i + 1] = '\0';
            return result;
        }
    }
    return "";
}