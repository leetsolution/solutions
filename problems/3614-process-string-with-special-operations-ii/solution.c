char processStr(char* s, long long k) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    char *processString(char *s, long long k) {
        char *result = (char *)malloc(1 * sizeof(char));
        result[0] = '\0';
        long long result_len = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                result = (char *)realloc(result, (result_len + 2) * sizeof(char));
                result[result_len++] = s[i];
                result[result_len] = '\0';
            } else if (s[i] == '*') {
                if (result_len > 0) {
                    result = (char *)realloc(result, (result_len) * sizeof(char));
                    result[--result_len] = '\0';
                }
            } else if (s[i] == '#') {
                char *temp = (char *)malloc((2 * result_len + 1) * sizeof(char));
                strcpy(temp, result);
                strcat(temp, result);
                free(result);
                result = temp;
                result_len *= 2;
            } else if (s[i] == '%') {
                char *temp = (char *)malloc((result_len + 1) * sizeof(char));
                for (long long j = 0; j < result_len; j++) {
                    temp[j] = result[result_len - 1 - j];
                }
                temp[result_len] = '\0';
                free(result);
                result = temp;
            }
        }

        if (k >= result_len || k < 0) {
            free(result);
            return ".";
        }
        char *ans = (char *)malloc(2 * sizeof(char));
        ans[0] = result[k];
        ans[1] = '\0';
        free(result);
        return ans;
    }
}