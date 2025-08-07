bool isFascinating(int n) {
    int num2 = 2 * n;
    int num3 = 3 * n;
    char str[10];
    sprintf(str, "%d%d%d", n, num2, num3);
    int count[10] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            return false;
        }
        count[str[i] - '0']++;
    }
    for (int i = 1; i <= 9; i++) {
        if (count[i] != 1) {
            return false;
        }
    }
    return true;
}