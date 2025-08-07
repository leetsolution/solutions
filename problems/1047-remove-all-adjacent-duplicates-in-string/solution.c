char* removeDuplicates(char* s) {
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (j > 0 && s[i] == s[j - 1]) {
            j--;
        } else {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
    return s;
}