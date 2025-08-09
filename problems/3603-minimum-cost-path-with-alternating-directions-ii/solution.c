#include <limits.h>
#include <stdlib.h>

long long minCost(int m, int n, int** waitCost, int waitCostSize, int* waitCostColSize) {
    long long** dp = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        dp[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }

    dp[0][0] = (long long)1;

    for (int move = 1; move <= 2 * (m + n - 2) + 1; move++) {
        long long** next_dp = (long long**)malloc(m * sizeof(long long*));
        for (int i = 0; i < m; i++) {
            next_dp[i] = (long long*)malloc(n * sizeof(long long));
            for (int j = 0; j < n; j++) {
                next_dp[i][j] = LLONG_MAX;
            }
        }

        if (move % 2 == 1) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] != LLONG_MAX) {
                        if (i + 1 < m) {
                            long long cost = (long long)(i + 2) * (long long)(j + 1);
                            if (dp[i][j] + cost < next_dp[i + 1][j]) {
                                next_dp[i + 1][j] = dp[i][j] + cost;
                            }
                        }
                        if (j + 1 < n) {
                            long long cost = (long long)(i + 1) * (long long)(j + 2);
                            if (dp[i][j] + cost < next_dp[i][j + 1]) {
                                next_dp[i][j + 1] = dp[i][j] + cost;
                            }
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] != LLONG_MAX) {
                        long long cost = (long long)waitCost[i][j];
                        if (dp[i][j] + cost < next_dp[i][j]) {
                            next_dp[i][j] = dp[i][j] + cost;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            free(dp[i]);
        }
        free(dp);

        dp = next_dp;
    }

    long long result = dp[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}