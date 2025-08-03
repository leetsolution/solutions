int minTime(char* s, int* order, int orderSize, int k) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int countValidSubstrings(char *s) {
        int n = strlen(s);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                char *substring = (char *)malloc((j - i + 2) * sizeof(char));
                strncpy(substring, s + i, j - i + 1);
                substring[j - i + 1] = '\0';
                int valid = 0;
                for (int k = 0; k <= j - i; k++) {
                    if (substring[k] == '*') {
                        valid = 1;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
                free(substring);
            }
        }
        return count;
    }

    int minTimeToActivateString(char *s, int *order, int k) {
        int n = strlen(s);
        char *modified_s = (char *)malloc((n + 1) * sizeof(char));
        strcpy(modified_s, s);
        for (int t = 0; t < n; t++) {
            modified_s[order[t]] = '*';
            if (countValidSubstrings(modified_s) >= k) {
                free(modified_s);
                return t;
            }
        }
        free(modified_s);
        return -1;
    }
}