bool digitCount(char* num) {
    int n = 0;
    while (num[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (num[j] - '0' == i) {
                count++;
            }
        }
        if (count != num[i] - '0') {
            return false;
        }
    }

    return true;
}