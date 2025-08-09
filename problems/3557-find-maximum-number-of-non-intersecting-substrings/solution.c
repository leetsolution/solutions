#include <stdio.h>
#include <string.h>

int maxSubstrings(char* word) {
    int n = strlen(word);
    int left[26], right[26];
    for (int i = 0; i < 26; i++) {
        left[i] = n;
        right[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = word[i] - 'a';
        left[c] = (left[c] > i) ? i : left[c];
        right[c] = (right[c] < i) ? i : right[c];
    }

    int intervals[n][2];
    int intervalCount = 0;
    for (int i = 0; i < 26; i++) {
        if (left[i] < right[i]) {
            int l = left[i];
            int r = right[i];
            int new_l = l;
            for (int j = l; j <= r; j++) {
                int c = word[j] - 'a';
                if (left[c] < l) {
                    new_l = -1;
                    break;
                }
                r = (r < right[c]) ? right[c] : r;
            }

            if (new_l != -1 && r - l + 1 >= 4) {
                intervals[intervalCount][0] = l;
                intervals[intervalCount][1] = r;
                intervalCount++;
            }
        }
    }

    qsort(intervals, intervalCount, sizeof(intervals[0]), [](const void* a, const void* b) {
        return ((int*)a)[1] - ((int*)b)[1];
    });

    int count = 0;
    int end = -1;
    for (int i = 0; i < intervalCount; i++) {
        if (intervals[i][0] > end) {
            count++;
            end = intervals[i][1];
        }
    }

    return count;
}