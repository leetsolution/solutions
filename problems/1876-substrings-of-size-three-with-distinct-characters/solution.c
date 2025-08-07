int countGoodSubstrings(char* s) {
    int count = 0;
    int n = strlen(s);
    for (int i = 0; i <= n - 3; i++) {
        char a = s[i];
        char b = s[i + 1];
        char c = s[i + 2];
        if (a != b && a != c && b != c) {
            count++;
        }
    }
    return count;
}