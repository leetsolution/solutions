int countValidWords(char* sentence) {
    int count = 0;
    int i = 0;
    while (sentence[i] != '\0') {
        while (sentence[i] == ' ') {
            i++;
        }
        if (sentence[i] == '\0') {
            break;
        }
        int start = i;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            i++;
        }
        int end = i - 1;
        int valid = 1;
        int hyphenCount = 0;
        int punctuationCount = 0;

        for (int j = start; j <= end; j++) {
            if (isdigit(sentence[j])) {
                valid = 0;
                break;
            } else if (sentence[j] == '-') {
                hyphenCount++;
                if (hyphenCount > 1) {
                    valid = 0;
                    break;
                }
                if (j == start || j == end) {
                    valid = 0;
                    break;
                }
                if (!islower(sentence[j - 1]) || !islower(sentence[j + 1])) {
                    valid = 0;
                    break;
                }
            } else if (sentence[j] == '!' || sentence[j] == '.' || sentence[j] == ',') {
                punctuationCount++;
                if (punctuationCount > 1) {
                    valid = 0;
                    break;
                }
                if (j != end) {
                    valid = 0;
                    break;
                }
            } else if (!islower(sentence[j]) && sentence[j] != ' ' && sentence[j] != '\0') {
                valid = 0;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }
    return count;
}