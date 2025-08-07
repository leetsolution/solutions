int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        int consistent = 1;
        for (int j = 0; words[i][j] != '\0'; j++) {
            int found = 0;
            for (int k = 0; allowed[k] != '\0'; k++) {
                if (words[i][j] == allowed[k]) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                consistent = 0;
                break;
            }
        }
        if (consistent == 1) {
            count++;
        }
    }
    return count;
}