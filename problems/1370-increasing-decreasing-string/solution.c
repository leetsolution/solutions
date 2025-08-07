#include <stdlib.h>
#include <string.h>

char* sortString(char* s) {
    int len = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int resultIndex = 0;

    while (resultIndex < len) {
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                result[resultIndex++] = 'a' + i;
                count[i]--;
            }
        }

        for (int i = 25; i >= 0; i--) {
            if (count[i] > 0) {
                result[resultIndex++] = 'a' + i;
                count[i]--;
            }
        }
    }

    result[len] = '\0';
    return result;
}