#include <string.h>
#include <stdlib.h>

char* reorderSpaces(char* text) {
    int spaces = 0;
    int words = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') {
            spaces++;
        }
    }

    char* temp = strdup(text);
    char* token = strtok(temp, " ");
    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }
    free(temp);

    int betweenSpaces = 0;
    int trailingSpaces = 0;
    if (words > 1) {
        betweenSpaces = spaces / (words - 1);
        trailingSpaces = spaces % (words - 1);
    } else {
        trailingSpaces = spaces;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[0] = '\0';

    temp = strdup(text);
    token = strtok(temp, " ");
    int i = 0;
    while (token != NULL) {
        strcat(result, token);
        i++;
        if (i < words) {
            for (int j = 0; j < betweenSpaces; j++) {
                strcat(result, " ");
            }
        }
        token = strtok(NULL, " ");
    }
    free(temp);

    for (int j = 0; j < trailingSpaces; j++) {
        strcat(result, " ");
    }

    int resultLen = strlen(result);
    result[resultLen] = '\0';

    return result;
}