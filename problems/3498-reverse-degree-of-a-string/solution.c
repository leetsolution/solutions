int reverseDegree(char* s) {
    int degree = 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        degree += (26 - (s[i] - 'a')) * (i + 1);
    }
    return degree;
}