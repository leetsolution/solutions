int splitNum(int num) {
    char s[10];
    sprintf(s, "%d", num);
    int n = strlen(s);
    int sum1 = 0, sum2 = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (s[i] < s[j]) {
            sum1 = sum1 * 10 + s[i] - '0';
            i++;
        } else {
            sum2 = sum2 * 10 + s[j] - '0';
            j--;
        }
    }
    return sum1 + sum2;
}