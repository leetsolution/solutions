int maxRepeating(char* sequence, char* word) {
    int sequence_len = 0;
    while (sequence[sequence_len] != '\0') {
        sequence_len++;
    }

    int word_len = 0;
    while (word[word_len] != '\0') {
        word_len++;
    }

    int max_k = 0;
    for (int k = 1; ; k++) {
        char repeated_word[10001] = "";
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < word_len; j++) {
                int len = 0;
                while (repeated_word[len] != '\0') {
                    len++;
                }
                repeated_word[len] = word[j];
                repeated_word[len + 1] = '\0';
            }
        }
        
        int repeated_word_len = 0;
        while(repeated_word[repeated_word_len] != '\0'){
            repeated_word_len++;
        }

        if (repeated_word_len == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i <= sequence_len - repeated_word_len; i++) {
            int match = 1;
            for (int j = 0; j < repeated_word_len; j++) {
                if (sequence[i + j] != repeated_word[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                found = 1;
                break;
            }
        }

        if (found) {
            max_k = k;
        } else {
            break;
        }
    }

    return max_k;
}