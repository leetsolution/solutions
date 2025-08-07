#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* clearDigits(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (top >= 0) {
                top--;
            }
        } else {
            stack[++top] = s[i];
        }
    }

    stack[top + 1] = '\0';
    char* result = (char*)malloc((top + 2) * sizeof(char));
    strcpy(result, stack);
    free(stack);
    return result;
}