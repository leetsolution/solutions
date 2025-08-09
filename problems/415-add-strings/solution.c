char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = (len1 > len2) ? len1 : len2;
    char *res = (char*)malloc((len + 2) * sizeof(char));
    int i = len1 - 1;
    int j = len2 - 1;
    int k = len;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (k == 0) {
        memmove(res + 1, res, len + 1);
        res[0] = '0';
        len++;

    }
    res[len + 1] = '\0';

    
    return res;
}