bool checkRecord(char* s) {
    int absentCount = 0;
    int lateCount = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'A') {
            absentCount++;
        } else if (s[i] == 'L') {
            lateCount++;
        } else {
            lateCount = 0;
        }
        if (absentCount >= 2 || lateCount >= 3) {
            return false;
        }
    }
    return true;
}