#include <string.h>
#include <stdbool.h>

bool isPrefixAndSuffix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2) {
        return false;
    }

    if (strncmp(str1, str2, len1) == 0 && strncmp(str1, str2 + len2 - len1, len1) == 0) {
        return true;
    }

    return false;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    return count;
}