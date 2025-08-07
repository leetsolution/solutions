#include <string.h>
#include <stdlib.h>

char* finalString(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (2 * len + 1));
    int res_len = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'i') {
            for (int j = 0; j < res_len / 2; j++) {
                char temp = res[j];
                res[j] = res[res_len - 1 - j];
                res[res_len - 1 - j] = temp;
            }
        } else {
            res[res_len++] = s[i];
        }
    }
    res[res_len] = '\0';
    return realloc(res, sizeof(char) * (res_len + 1));
}