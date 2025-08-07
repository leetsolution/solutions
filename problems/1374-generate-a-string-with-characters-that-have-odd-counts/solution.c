#include <stdlib.h>

char* generateTheString(int n) {
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    if (n % 2 == 0) {
        for (int i = 0; i < n - 1; i++) {
            result[i] = 'a';
        }
        result[n - 1] = 'b';
    } else {
        for (int i = 0; i < n; i++) {
            result[i] = 'a';
        }
    }
    result[n] = '\0';
    return result;
}