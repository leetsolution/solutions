#include <stdlib.h>
#include <string.h>

char* thousandSeparator(int n) {
    if (n < 1000) {
        char *result = (char *)malloc(sizeof(char) * (10));
        sprintf(result, "%d", n);
        return result;
    }
    char num_str[12];
    sprintf(num_str, "%d", n);
    int len = strlen(num_str);
    int count = 0;
    char *result = (char *)malloc(sizeof(char) * (len + len / 3 + 1));
    int k=0;
    for (int i = len - 1; i >= 0; i--) {
        result[k++] = num_str[i];
        count++;
        if (count == 3 && i != 0) {
            result[k++] = '.';
            count = 0;
        }
    }
    int j = 0;
    for (int i = k - 1; i >= 0; i--) {
        num_str[j++] = result[i];
    }
    num_str[j] = '\0';
    
    char *final_result = (char *)malloc(sizeof(char) * (strlen(num_str) + 1));
    strcpy(final_result, num_str);

    free(result);

    return final_result;
}