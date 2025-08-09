int lengthOfLastWord(char* s) {
    int length = 0;
    int i = 0;
    int last_word_length = 0;

    while (s[i] != '\0') {
        if (s[i] != ' ') {
            length++;
        } else {
            if (length > 0) {
                last_word_length = length;
            }
            length = 0;
        }
        i++;
    }

    if (length > 0) {
        return length;
    } else {
        i = i - 2;
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        length = 0;
        while(i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
}