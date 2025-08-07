#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(points[0]), compare);
    int maxWidth = 0;
    for (int i = 1; i < pointsSize; i++) {
        int width = points[i][0] - points[i - 1][0];
        if (width > maxWidth) {
            maxWidth = width;
        }
    }
    return maxWidth;
}