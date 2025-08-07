bool checkAlmostEquivalent(char* word1, char* word2) {
    int freq[26] = {0};
    for (int i = 0; word1[i] != '\0'; i++) {
        freq[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i] != '\0'; i++) {
        freq[word2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 3 || freq[i] < -3) {
            return false;
        }
    }
    return true;
}