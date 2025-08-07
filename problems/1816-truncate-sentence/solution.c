char* truncateSentence(char* s, int k) {
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            count++;
            if (count == k) {
                s[i] = '\0';
                break;
            }
        }
        i++;
    }
    return s;
}