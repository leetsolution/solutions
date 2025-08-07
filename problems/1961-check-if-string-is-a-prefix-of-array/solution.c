bool isPrefixString(char* s, char** words, int wordsSize) {
    int s_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }

    int current_len = 0;
    for (int i = 0; i < wordsSize; i++) {
        int word_len = 0;
        while (words[i][word_len] != '\0') {
            word_len++;
        }

        for (int j = 0; j < word_len; j++) {
            if (current_len + j >= s_len || s[current_len + j] != words[i][j]) {
                return false;
            }
        }
        current_len += word_len;
        
        if (current_len == s_len) {
            return true;
        } else if (current_len > s_len) {
            return false;
        }
    }

    return false;
}