#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* processStr(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len * len + 1));
    result[0] = '\0';
    int result_len = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            result[result_len++] = s[i];
            result[result_len] = '\0';
        } else if (s[i] == '*') {
            if (result_len > 0) {
                result_len--;
                result[result_len] = '\0';
            }
        } else if (s[i] == '#') {
            int temp_len = result_len;
            for (int j = 0; j < temp_len; j++) {
                result[result_len++] = result[j];
            }
            result[result_len] = '\0';
        } else if (s[i] == '%') {
            int left = 0;
            int right = result_len - 1;
            while (left < right) {
                char temp = result[left];
                result[left] = result[right];
                result[right] = temp;
                left++;
                right--;
            }
        }
    }

    char* final_result = (char*)malloc(sizeof(char) * (result_len + 1));
    strcpy(final_result, result);
    free(result);
    return final_result;
}