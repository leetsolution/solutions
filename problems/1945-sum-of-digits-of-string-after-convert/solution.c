int getLucky(char* s, int k) {
    int num = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int val = s[i] - 'a' + 1;
        if (val < 10) {
            num += val;
        } else {
            num += (val / 10) + (val % 10);
        }
    }

    for (int i = 1; i < k; i++) {
        int next_num = 0;
        while (num > 0) {
            next_num += num % 10;
            num /= 10;
        }
        num = next_num;
    }
    return num;
}