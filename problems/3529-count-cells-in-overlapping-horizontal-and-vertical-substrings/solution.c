#include <string.h>
#include <stdlib.h>

int countCells(char** grid, int gridSize, int* gridColSize, char* pattern) {
    int m = gridSize;
    int n = gridColSize[0];
    int pattern_len = strlen(pattern);
    int count = 0;
    int** horizontal = (int**)malloc(m * sizeof(int*));
    int** vertical = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        horizontal[i] = (int*)malloc(n * sizeof(int));
        vertical[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            horizontal[i][j] = 0;
            vertical[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int k = 0;
            while (k < pattern_len) {
                if (grid[(i * n + j + k) / n % m][(j + k) % n] != pattern[k]) {
                    break;
                }
                k++;
            }
            if (k == pattern_len) {
                for (int l = 0; l < pattern_len; l++) {
                    horizontal[(i * n + j + l) / n % m][(j + l) % n] = 1;
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int k = 0;
            while (k < pattern_len) {
                if (grid[(i + k) % m][(j * m + i + k) / m % n] != pattern[k]) {
                    break;
                }
                k++;
            }
            if (k == pattern_len) {
                for (int l = 0; l < pattern_len; l++) {
                    vertical[(i + l) % m][(j * m + i + l) / m % n] = 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (horizontal[i][j] == 1 && vertical[i][j] == 1) {
                count++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(horizontal[i]);
        free(vertical[i]);
    }
    free(horizontal);
    free(vertical);

    return count;
}