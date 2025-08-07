int rearrangeCharacters(char* s, char* target) {
    int s_freq[26] = {0};
    int target_freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        s_freq[s[i] - 'a']++;
    }

    for (int i = 0; target[i] != '\0'; i++) {
        target_freq[target[i] - 'a']++;
    }

    int min_copies = -1;
    for (int i = 0; i < 26; i++) {
        if (target_freq[i] > 0) {
            if (s_freq[i] == 0) return 0;
            int copies = s_freq[i] / target_freq[i];
            if (min_copies == -1 || copies < min_copies) {
                min_copies = copies;
            }
        }
    }

    return min_copies;
}