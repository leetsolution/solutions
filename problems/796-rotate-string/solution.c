bool rotateString(char* s, char* goal) {
    int len = strlen(s);
    if (len != strlen(goal)) return false;
    char *temp = (char *)malloc((len + 1) * sizeof(char));
    strcpy(temp, s);
    for (int i = 0; i < len; i++) {
        if (strcmp(temp, goal) == 0) return true;
        char first = temp[0];
        for (int j = 0; j < len - 1; j++) {
            temp[j] = temp[j + 1];
        }
        temp[len - 1] = first;
    }
    free(temp);
    return false;
}