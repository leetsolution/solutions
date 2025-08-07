int possibleStringCount(char* word) {
    int n = 0;
    while (word[n] != '\0') {
        n++;
    }

    int count = 1;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && word[i] == word[j]) {
            j++;
        }
        if (j - i > 1) {
            count += (j - i - 1);
            i = j;
        } else {
            i++;
        }
    }

    return count;
}