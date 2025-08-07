int canBeTypedWords(char* text, char* brokenLetters) {
    int count = 0;
    int canType = 1;
    int i = 0;
    int j = 0;

    while (text[i] != '\0') {
        if (text[i] == ' ') {
            if (canType) {
                count++;
            }
            canType = 1;
        } else {
            j = 0;
            while (brokenLetters[j] != '\0') {
                if (text[i] == brokenLetters[j]) {
                    canType = 0;
                    break;
                }
                j++;
            }
        }
        i++;
    }

    if (canType) {
        count++;
    }

    return count;
}