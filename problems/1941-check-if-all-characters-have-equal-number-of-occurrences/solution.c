bool areOccurrencesEqual(char* s) {
    int freq[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
        freq[s[i] - 'a']++;
        i++;
    }
    int count = 0;
    for (int j = 0; j < 26; j++) {
        if (freq[j] > 0) {
            count = freq[j];
            break;
        }
    }
    for (int j = 0; j < 26; j++) {
        if (freq[j] > 0 && freq[j] != count) {
            return false;
        }
    }
    return true;
}