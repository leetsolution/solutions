#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

int computeTopRight(int** fruits, int n) {
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) dp[i] = (int*)calloc(n, sizeof(int));
    dp[0][n - 1] = fruits[0][n - 1];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x >= y && !(x == n - 1 && y == n - 1)) continue;
            int dirs[3][2] = { {1, -1}, {1, 0}, {1, 1} };
            for (int d = 0; d < 3; d++) {
                int i = x - dirs[d][0], j = y - dirs[d][1];
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (i < j && j < n - 1 - i) continue;
                dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
            }
        }
    }
    int result = dp[n - 1][n - 1];
    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    return result;
}

int computeBottomLeft(int** fruits, int n) {
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) dp[i] = (int*)calloc(n, sizeof(int));
    dp[n - 1][0] = fruits[n - 1][0];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x <= y && !(x == n - 1 && y == n - 1)) continue;
            int dirs[3][2] = { {-1, 1}, {0, 1}, {1, 1} };
            for (int d = 0; d < 3; d++) {
                int i = x - dirs[d][0], j = y - dirs[d][1];
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (j < i && i < n - 1 - j) continue;
                dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
            }
        }
    }
    int result = dp[n - 1][n - 1];
    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    return result;
}

int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int n = fruitsSize;
    int mainDiagonal = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonal += fruits[i][i];
    }
    int topRight = computeTopRight(fruits, n);
    int bottomLeft = computeBottomLeft(fruits, n);
    // Subtract bottom-right corner twice
    return mainDiagonal + topRight + bottomLeft - 2 * fruits[n - 1][n - 1];
}
