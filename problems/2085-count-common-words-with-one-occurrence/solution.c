#include <string.h>
#include <stdlib.h>

int countWords(char** words1, int words1Size, char** words2, int words2Size) {
    int count = 0;
    for (int i = 0; i < words1Size; i++) {
        int count1 = 0;
        for (int j = 0; j < words1Size; j++) {
            if (strcmp(words1[i], words1[j]) == 0) {
                count1++;
            }
        }
        if (count1 == 1) {
            int count2 = 0;
            for (int k = 0; k < words2Size; k++) {
                if (strcmp(words1[i], words2[k]) == 0) {
                    count2++;
                }
            }
            if (count2 == 1) {
                count++;
            }
        }
    }
    return count;
}