/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    if (wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int resultSize = 0;

    result[resultSize++] = words[0];

    for (int i = 1; i < wordsSize; i++) {
        int count1[26] = {0};
        int count2[26] = {0};

        for (int j = 0; words[i - 1][j] != '\0'; j++) {
            count1[words[i - 1][j] - 'a']++;
        }

        for (int j = 0; words[i][j] != '\0'; j++) {
            count2[words[i][j] - 'a']++;
        }

        int anagram = 1;
        for (int j = 0; j < 26; j++) {
            if (count1[j] != count2[j]) {
                anagram = 0;
                break;
            }
        }

        if (!anagram) {
            result[resultSize++] = words[i];
        }
    }

    *returnSize = resultSize;
    return result;
}