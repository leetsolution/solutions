/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findOcurrences(char* text, char* first, char* second, int* returnSize) {
    char** result = NULL;
    *returnSize = 0;
    int capacity = 0;

    char* token = strtok(text, " ");
    char* prev = NULL;
    char* prevprev = NULL;

    while (token != NULL) {
        if (prevprev != NULL && prev != NULL && strcmp(prevprev, first) == 0 && strcmp(prev, second) == 0) {
            if (*returnSize == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                result = (char**)realloc(result, capacity * sizeof(char*));
                if (result == NULL) {
                    return NULL; 
                }
            }
            result[*returnSize] = (char*)malloc(strlen(token) + 1);
            if (result[*returnSize] == NULL) {
                return NULL;
            }
            strcpy(result[*returnSize], token);
            (*returnSize)++;
        }
        prevprev = prev;
        prev = token;
        token = strtok(NULL, " ");
    }

    return result;
}