bool isCircularSentence(char* sentence) {
    int len = 0;
    while (sentence[len] != '\0') {
        len++;
    }

    if (len == 0) {
        return true;
    }

    int wordCount = 1;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            wordCount++;
        }
    }

    if (wordCount == 1) {
        return sentence[0] == sentence[len - 1];
    }

    int start = 0;
    int end;
    for (int i = 0; i < wordCount - 1; i++) {
        end = start;
        while (sentence[end] != ' ') {
            end++;
        }
        if (sentence[end - 1] != sentence[end + 1]) {
            return false;
        }
        start = end + 1;
    }

    if (sentence[len - 1] != sentence[0]) {
        return false;
    }

    return true;
}