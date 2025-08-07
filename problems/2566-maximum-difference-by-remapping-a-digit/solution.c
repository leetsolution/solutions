int minMaxDifference(int num) {
    char s[10];
    sprintf(s, "%d", num);
    int n = strlen(s);

    int max_num = num;
    for (int i = 0; i < n; i++) {
        char digit_to_replace = s[i];
        char temp[10];
        strcpy(temp, s);
        for (int j = 0; j < n; j++) {
            if (temp[j] == digit_to_replace) {
                temp[j] = '9';
            }
        }
        max_num = atoi(temp);
        break;
    }

    int min_num = num;
    for (int i = 0; i < n; i++) {
        char digit_to_replace = s[i];
        char temp[10];
        strcpy(temp, s);
        for (int j = 0; j < n; j++) {
            if (temp[j] == digit_to_replace) {
                temp[j] = (i == 0) ? '0' : '0';
            }
        }
          min_num = atoi(temp);
        break;
    }

    return max_num - min_num;
}