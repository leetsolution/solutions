#include <stdlib.h>

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
    int answer = 0;
    int cols = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = j + 1; k < cols; k++) {
                if (grid[i][j] > grid[i][k]) {
                    int temp = grid[i][j];
                    grid[i][j] = grid[i][k];
                    grid[i][k] = temp;
                }
            }
        }
    }

    for (int j = 0; j < cols; j++) {
        int max_val = 0;
        for (int i = 0; i < gridSize; i++) {
            if (grid[i][j] > max_val) {
                max_val = grid[i][j];
            }
        }
        answer += max_val;
    }

    return answer;
}