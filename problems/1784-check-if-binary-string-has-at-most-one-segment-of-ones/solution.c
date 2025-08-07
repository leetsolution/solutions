bool checkOnesSegment(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    int ones_ended = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ones_ended = 1;
        } else if (ones_ended && s[i] == '1') {
            return false;
        }
    }

    return true;
}