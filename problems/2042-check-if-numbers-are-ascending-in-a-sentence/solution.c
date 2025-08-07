#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool areNumbersAscending(char* s) {
    int prev = -1;
    char* token = strtok(s, " ");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            int num = atoi(token);
            if (num <= prev) {
                return false;
            }
            prev = num;
        }
        token = strtok(NULL, " ");
    }
    return true;
}