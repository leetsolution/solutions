#include <string.h>
#include <stdlib.h>

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) {
        char* temp = str1;
        str1 = str2;
        str2 = temp;
        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
    }

    for (int i = len2; i >= 1; i--) {
        if (len1 % i == 0 && len2 % i == 0) {
            char temp[i + 1];
            strncpy(temp, str2, i);
            temp[i] = '\0';

            int count1 = len1 / i;
            int count2 = len2 / i;

            char tempStr1[len1 + 1];
            tempStr1[0] = '\0';
            for (int j = 0; j < count1; j++) {
                strcat(tempStr1, temp);
            }

            char tempStr2[len2 + 1];
            tempStr2[0] = '\0';
            for (int j = 0; j < count2; j++) {
                strcat(tempStr2, temp);
            }

            if (strcmp(tempStr1, str1) == 0 && strcmp(tempStr2, str2) == 0) {
                char* result = (char*)malloc(i + 1);
                strncpy(result, temp, i);
                result[i] = '\0';
                return result;
            }
        }
    }
    return "";
}