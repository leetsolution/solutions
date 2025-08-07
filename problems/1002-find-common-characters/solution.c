/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** words, int wordsSize, int* returnSize) {
    int minFreq[26] = {0};
    for (int i = 0; i < 26; i++) {
        minFreq[i] = 101;
    }

    for (int i = 0; i < wordsSize; i++) {
        int freq[26] = {0};
        for (int j = 0; words[i][j] != '\0'; j++) {
            freq[words[i][j] - 'a']++;
        }

        for (int k = 0; k < 26; k++) {
            minFreq[k] = (freq[k] < minFreq[k]) ? freq[k] : minFreq[k];
        }
    }

    int totalChars = 0;
    for (int i = 0; i < 26; i++) {
        totalChars += minFreq[i];
    }

    char** result = (char**)malloc(sizeof(char*) * totalChars);
    *returnSize = totalChars;

    int index = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < minFreq[i]; j++) {
            result[index] = (char*)malloc(sizeof(char) * 2);
            result[index][0] = (char)(i + 'a');
            result[index][1] = '\0';
            index++;
        }
    }

    return result;
}