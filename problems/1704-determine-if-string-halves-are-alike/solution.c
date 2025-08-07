bool halvesAreAlike(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int mid = len / 2;
    int countA = 0;
    int countB = 0;

    for (int i = 0; i < mid; i++) {
        char ch = s[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            countA++;
        }
    }

    for (int i = mid; i < len; i++) {
        char ch = s[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            countB++;
        }
    }

    return countA == countB;
}