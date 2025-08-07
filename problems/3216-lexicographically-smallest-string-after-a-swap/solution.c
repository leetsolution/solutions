#include <string.h>
#include <stdlib.h>

char* getSmallestString(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char smallest = s[i];
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((s[i] - '0') % 2 == (s[j] - '0') % 2 && s[j] < smallest) {
                smallest = s[j];
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            char temp = s[smallestIndex];
            for (int k = smallestIndex; k > i; k--) {
                s[k] = s[k - 1];
            }
            s[i] = temp;
        }
    }
    return s;
}