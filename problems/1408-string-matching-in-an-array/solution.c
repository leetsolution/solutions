/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i != j) {
                if (strstr(words[j], words[i]) != NULL) {
                    result[*returnSize] = strdup(words[i]);
                    (*returnSize)++;
                    break;
                }
            }
        }
    }

    return result;
}