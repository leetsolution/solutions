/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** partitionString(char* s, int* returnSize) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    char** segments = (char**)malloc((n + 1) * sizeof(char*));
    *returnSize = 0;

    int start = 0;
    while (start < n) {
        int end = start;
        char* currentSegment = (char*)malloc((n - start + 1) * sizeof(char));
        int currentSegmentLength = 0;

        while (end < n) {
            currentSegment[currentSegmentLength++] = s[end];
            currentSegment[currentSegmentLength] = '\0';

            int found = 0;
            for (int i = 0; i < *returnSize; i++) {
                int j = 0;
                while (segments[i][j] != '\0' && currentSegment[j] != '\0' && segments[i][j] == currentSegment[j]) {
                    j++;
                }
                if (segments[i][j] == '\0' && currentSegment[j] == '\0') {
                    found = 1;
                    break;
                }
            }

            if (found) {
                if (currentSegmentLength > 1) {
                    currentSegmentLength--;
                    currentSegment[currentSegmentLength] = '\0';
                    segments[*returnSize] = (char*)malloc((currentSegmentLength + 1) * sizeof(char));
                    for (int i = 0; i < currentSegmentLength; i++) {
                        segments[*returnSize][i] = currentSegment[i];
                    }
                    segments[*returnSize][currentSegmentLength] = '\0';
                    (*returnSize)++;
                    start = end;
                    break;
                } else {
                    currentSegmentLength++;
                    currentSegment[currentSegmentLength] = '\0';
                    end++;
                }
            } else {
                segments[*returnSize] = (char*)malloc((currentSegmentLength + 1) * sizeof(char));
                for (int i = 0; i < currentSegmentLength; i++) {
                    segments[*returnSize][i] = currentSegment[i];
                }
                segments[*returnSize][currentSegmentLength] = '\0';
                (*returnSize)++;
                start = end + 1;
                end++;
                break;
            }
        }
        if(end == n && start < n){
                segments[*returnSize] = (char*)malloc((currentSegmentLength + 1) * sizeof(char));
                for (int i = 0; i < currentSegmentLength; i++) {
                    segments[*returnSize][i] = currentSegment[i];
                }
                segments[*returnSize][currentSegmentLength] = '\0';
                (*returnSize)++;
                start = end;
        }

        free(currentSegment);
    }

    return segments;
}