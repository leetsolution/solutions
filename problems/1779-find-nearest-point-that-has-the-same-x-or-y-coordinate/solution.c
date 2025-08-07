#include <stdlib.h>

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize) {
    int minDist = -1;
    int minIndex = -1;
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] == x || points[i][1] == y) {
            int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (minDist == -1 || dist < minDist) {
                minDist = dist;
                minIndex = i;
            }
        }
    }
    return minIndex;
}