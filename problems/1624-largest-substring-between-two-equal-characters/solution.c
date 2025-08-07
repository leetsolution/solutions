int maxLengthBetweenEqualCharacters(char* s) {
    int first_occurrence[26];
    for (int i = 0; i < 26; i++) {
        first_occurrence[i] = -1;
    }
    int max_length = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        int char_index = s[i] - 'a';
        if (first_occurrence[char_index] == -1) {
            first_occurrence[char_index] = i;
        } else {
            int length = i - first_occurrence[char_index] - 1;
            if (length > max_length) {
                max_length = length;
            }
        }
    }
    return max_length;
}