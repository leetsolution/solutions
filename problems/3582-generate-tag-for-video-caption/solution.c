#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* generateTag(char* caption) {
    int len = strlen(caption);
    char* temp = (char*)malloc(len + 2);
    int tempIndex = 0;
    temp[tempIndex++] = '#';
    int wordStart = 0;
    int firstWord = 1;

    for (int i = 0; i < len; i++) {
        if (caption[i] == ' ') {
            if (i > wordStart) {
                if (!firstWord) {
                    temp[tempIndex++] = toupper(caption[wordStart]);
                } else {
                    temp[tempIndex++] = tolower(caption[wordStart]);
                }
                for (int j = wordStart + 1; j < i; j++) {
                    temp[tempIndex++] = tolower(caption[j]);
                }
                firstWord = 0;
            }
            wordStart = i + 1;
        }
    }

    if (len > wordStart) {
        if (!firstWord) {
            temp[tempIndex++] = toupper(caption[wordStart]);
        } else {
            temp[tempIndex++] = tolower(caption[wordStart]);
        }

        for (int j = wordStart + 1; j < len; j++) {
            temp[tempIndex++] = tolower(caption[j]);
        }
    }

    temp[tempIndex] = '\0';

    char* result = (char*)malloc(102);
    int resultIndex = 0;
    result[resultIndex++] = '#';
    for(int i=1; i<strlen(temp); i++){
        if(isalpha(temp[i])){
            result[resultIndex++] = temp[i];
        }
    }
    result[resultIndex] = '\0';
    if (strlen(result) > 100) {
        result[100] = '\0';
    }

    free(temp);
    return result;
}