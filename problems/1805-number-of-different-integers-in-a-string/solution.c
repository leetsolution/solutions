#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int numDifferentIntegers(char* word) {
    int len = strlen(word);
    char* numStr = (char*)malloc((len + 1) * sizeof(char));
    memset(numStr, 0, (len + 1) * sizeof(char));
    int numStrLen = 0;
    
    bool inNumber = false;
    for (int i = 0; i < len; i++) {
        if (word[i] >= '0' && word[i] <= '9') {
            numStr[numStrLen++] = word[i];
            inNumber = true;
        } else {
            if (inNumber) {
                numStr[numStrLen++] = ' ';
                inNumber = false;
            }
        }
    }
    
    if (numStrLen > 0 && numStr[numStrLen - 1] != ' ') {
        numStr[numStrLen++] = ' ';
    }
    numStr[numStrLen] = '\0';
    
    int count = 0;
    char* token = strtok(numStr, " ");
    
    char** numbers = NULL;
    int numCount = 0;
    
    while (token != NULL) {
        int tokenLen = strlen(token);
        int start = 0;
        while (start < tokenLen - 1 && token[start] == '0') {
            start++;
        }
        
        char* cleanedToken = token + start;
        int cleanedTokenLen = tokenLen - start;
        if (cleanedTokenLen == 0) cleanedTokenLen = 1;
        
        bool found = false;
        for (int i = 0; i < numCount; i++) {
            if (strlen(numbers[i]) == cleanedTokenLen && strncmp(numbers[i], cleanedToken, cleanedTokenLen) == 0) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            count++;
            numbers = (char**)realloc(numbers, (numCount + 1) * sizeof(char*));
            numbers[numCount] = (char*)malloc((cleanedTokenLen + 1) * sizeof(char));
            strncpy(numbers[numCount], cleanedToken, cleanedTokenLen);
            numbers[numCount][cleanedTokenLen] = '\0';
            numCount++;
        }
        
        token = strtok(NULL, " ");
    }
    
    for (int i = 0; i < numCount; i++) {
        free(numbers[i]);
    }
    free(numbers);
    free(numStr);
    
    return count;
}