int countSegments(char* s) {
    int count = 0;
    int inSegment = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            inSegment = 0;
        } else if (inSegment == 0) {
            count++;
            inSegment = 1;
        }
    }
    return count;
}