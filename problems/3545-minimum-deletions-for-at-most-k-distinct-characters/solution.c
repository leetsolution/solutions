int minDeletion(char* s, int k) {
    int freq[26] = {0};
    int n = 0;
    while (s[n] != '\0') {
        freq[s[n] - 'a']++;
        n++;
    }

    int distinct = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            distinct++;
        }
    }

    if (distinct <= k) {
        return 0;
    }

    int counts[26] = {0};
    int countSize = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            counts[countSize++] = freq[i];
        }
    }

    for (int i = 0; i < countSize - 1; i++) {
        for (int j = 0; j < countSize - i - 1; j++) {
            if (counts[j] > counts[j + 1]) {
                int temp = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = temp;
            }
        }
    }

    int deletions = 0;
    for (int i = 0; i < countSize - k; i++) {
        deletions += counts[i];
    }

    return deletions;
}