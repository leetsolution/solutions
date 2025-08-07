char* removeDigit(char* number, char digit) {
    int len = strlen(number);
    char *maxNum = NULL;
    for (int i = 0; i < len; i++) {
        if (number[i] == digit) {
            char *temp = (char *)malloc(len);
            strncpy(temp, number, i);
            strcat(temp, number + i + 1);
            if (maxNum == NULL || strcmp(temp, maxNum) > 0) {
                free(maxNum);
                maxNum = temp;
            } else {
                free(temp);
            }
        }
    }
    return maxNum;
}