int minOperations(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    int count1 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == '1') {
                count1++;
            }
        } else {
            if (s[i] == '0') {
                count1++;
            }
        }
    }

    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                count2++;
            }
        } else {
            if (s[i] == '1') {
                count2++;
            }
        }
    }

    return (count1 < count2) ? count1 : count2;
}