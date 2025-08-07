#include <string.h>
#include <stdlib.h>

int minimumPushes(char* word) {
    int len = strlen(word);
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[word[i] - 'a']++;
    }
    
    int pushes = 0;
    int keys[8] = {0};
    
    for (int i = 0; i < 26; i++) {
        int maxIndex = 0;
        int maxCount = 0;
        for (int j = 0; j < 26; j++) {
            if (count[j] > maxCount) {
                maxCount = count[j];
                maxIndex = j;
            }
        }
        
        if (maxCount == 0) {
            break;
        }
        
        count[maxIndex] = 0;
        
        int minKeyIndex = -1;
        int minKeyVal = 4; 

        for (int k = 0; k < 8; k++) {
            if (keys[k] < minKeyVal) {
                minKeyVal = keys[k];
                minKeyIndex = k;
            }
        }

        keys[minKeyIndex]++;

        if (keys[minKeyIndex] == 1) {
            pushes += maxCount;
        } else if (keys[minKeyIndex] == 2) {
            pushes += 2 * maxCount;
        } else if (keys[minKeyIndex] == 3) {
            pushes += 3 * maxCount;
        } else {
            pushes += 4 * maxCount;
        }
    }
    
    return pushes;
}