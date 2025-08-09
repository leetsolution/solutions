int minTime(char* s, int* order, int orderSize, int k) {
    int n = orderSize;
    char* temp_s = (char*)malloc((n + 1) * sizeof(char));
    strcpy(temp_s, s);

    for (int i = 0; i < n; i++) {
        temp_s[order[i]] = '*';
        long long count = 0;
        for (int j = 0; j < n; j++) {
            for (int l = j; l < n; l++) {
                int valid = 0;
                for (int m = j; m <= l; m++) {
                    if (temp_s[m] == '*') {
                        valid = 1;
                        break;
                    }
                }
                if (valid) {
                    count++;
                }
            }
        }

        if (count >= k) {
            free(temp_s);
            return i;
        }
    }

    free(temp_s);
    return -1;
}