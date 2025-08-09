#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    char* result = (char*)malloc(sizeof(char) * (maxLen + 2));
    int carry = 0;
    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';
    
    int len = strlen(result);
    char* reversedResult = (char*)malloc(sizeof(char) * (len + 1));
    for (int l = 0; l < len; l++) {
        reversedResult[l] = result[len - 1 - l];
    }
    reversedResult[len] = '\0';

    free(result);
    return reversedResult;
}