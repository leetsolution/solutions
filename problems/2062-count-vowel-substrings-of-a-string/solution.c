int countVowelSubstrings(char* word) {
    int count = 0;
    int n = 0;
    while (word[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int a = 0, e = 0, ii = 0, o = 0, u = 0;
            int valid = 1;
            for (int k = i; k <= j; k++) {
                if (word[k] == 'a') a = 1;
                else if (word[k] == 'e') e = 1;
                else if (word[k] == 'i') ii = 1;
                else if (word[k] == 'o') o = 1;
                else if (word[k] == 'u') u = 1;
                else {
                    valid = 0;
                    break;
                }
            }
            if (valid && a && e && ii && o && u) {
                count++;
            }
        }
    }

    return count;
}