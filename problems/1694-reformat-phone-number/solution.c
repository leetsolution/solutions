char* reformatNumber(char* number) {
    int len = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            len++;
        }
    }

    char* digits = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            digits[j++] = number[i];
        }
    }
    digits[len] = '\0';

    int res_len = len + (len - 1) / 3;
    if (len % 3 == 1 && len > 3) {
        res_len--;
    }
    
    char* result = (char*)malloc((res_len + 1) * sizeof(char));
    int k = 0;
    int i = 0;
    while (len > 4) {
        result[k++] = digits[i++];
        result[k++] = digits[i++];
        result[k++] = digits[i++];
        result[k++] = '-';
        len -= 3;
    }

    if (len == 4) {
        result[k++] = digits[i++];
        result[k++] = digits[i++];
        result[k++] = '-';
        result[k++] = digits[i++];
        result[k++] = digits[i++];
    } else if (len == 3) {
        result[k++] = digits[i++];
        result[k++] = digits[i++];
        result[k++] = digits[i++];
    } else if (len == 2) {
        result[k++] = digits[i++];
        result[k++] = digits[i++];
    }

    if (k > 0 && result[k - 1] == '-') {
        result[k - 1] = '\0';
    } else {
        result[k] = '\0';
    }

    free(digits);
    return result;
}