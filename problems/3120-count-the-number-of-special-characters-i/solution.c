int numberOfSpecialChars(char* word) {
    int lowercase[26] = {0};
    int uppercase[26] = {0};
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            lowercase[word[i] - 'a'] = 1;
        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            uppercase[word[i] - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (lowercase[i] == 1 && uppercase[i] == 1) {
            count++;
        }
    }
    return count;
}