#include <stdbool.h>
#include <string.h>

bool isSubstringPresent(char* s) {
    int len = strlen(s);
    if (len < 2) {
        return false;
    }

    char reversed_s[len + 1];
    strcpy(reversed_s, s);

    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = reversed_s[i];
        reversed_s[i] = reversed_s[j];
        reversed_s[j] = temp;
    }

    for (i = 0; i <= len - 2; i++) {
        char sub[3];
        sub[0] = s[i];
        sub[1] = s[i + 1];
        sub[2] = '\0';

        if (strstr(reversed_s, sub) != NULL) {
            return true;
        }
    }

    return false;
}