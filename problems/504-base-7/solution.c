char* convertToBase7(int num) {
    if (num == 0) {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    char *result;
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    int len = 0;
    int temp = num;
    while (temp > 0) {
        temp /= 7;
        len++;
    }
    len += (sign == -1);
    result = (char *)malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    if (sign == -1) {
        result[0] = '-';
    }
    int i = len - 1;
    if (sign == -1) {
        i--;
    }
    while (num > 0) {
        result[i] = num % 7 + '0';
        num /= 7;
        i--;
    }
    return result;
}