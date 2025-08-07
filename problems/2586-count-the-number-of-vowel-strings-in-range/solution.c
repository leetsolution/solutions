int vowelStrings(char** words, int wordsSize, int left, int right) {
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = left; i <= right; i++) {
        char* word = words[i];
        int len = strlen(word);
        int start = 0;
        int end = len - 1;
        int isVowelStart = 0;
        int isVowelEnd = 0;
        for (int j = 0; j < 5; j++) {
            if (word[start] == vowels[j]) {
                isVowelStart = 1;
                break;
            }
        }
        for (int j = 0; j < 5; j++) {
            if (word[end] == vowels[j]) {
                isVowelEnd = 1;
                break;
            }
        }
        if (isVowelStart && isVowelEnd) {
            count++;
        }
    }
    return count;
}