bool equalFrequency(char* word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }

    if (len <= 1) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        int freq[26] = {0};
        char temp[101];
        int k = 0;
        for (int j = 0; j < len; j++) {
            if (i != j) {
                temp[k++] = word[j];
            }
        }
        temp[k] = '\0';

        for (int j = 0; j < k; j++) {
            freq[temp[j] - 'a']++;
        }

        int first_freq = -1;
        bool equal = true;
        for (int j = 0; j < 26; j++) {
            if (freq[j] > 0) {
                if (first_freq == -1) {
                    first_freq = freq[j];
                } else if (freq[j] != first_freq) {
                    equal = false;
                    break;
                }
            }
        }

        if (equal) {
            return true;
        }
    }

    return false;
}