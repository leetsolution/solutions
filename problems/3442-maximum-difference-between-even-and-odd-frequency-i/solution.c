int maxDifference(char* s) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    int maxOdd = -1;
    int minEven = 101;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 0 && freq[i] > 0) {
            if (freq[i] < minEven) {
                minEven = freq[i];
            }
        } else if (freq[i] % 2 != 0) {
            if (freq[i] > maxOdd) {
                maxOdd = freq[i];
            }
        }
    }
    return maxOdd - minEven;
}