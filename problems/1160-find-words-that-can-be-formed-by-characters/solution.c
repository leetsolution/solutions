int countCharacters(char** words, int wordsSize, char* chars) {
    int char_counts[26] = {0};
    for (int i = 0; chars[i] != '\0'; i++) {
        char_counts[chars[i] - 'a']++;
    }

    int total_length = 0;
    for (int i = 0; i < wordsSize; i++) {
        int word_counts[26] = {0};
        int j = 0;
        while (words[i][j] != '\0') {
            word_counts[words[i][j] - 'a']++;
            j++;
        }

        int is_good = 1;
        for (int k = 0; k < 26; k++) {
            if (word_counts[k] > char_counts[k]) {
                is_good = 0;
                break;
            }
        }

        if (is_good) {
            total_length += j;
        }
    }

    return total_length;
}