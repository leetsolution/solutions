#include <stdlib.h>
#include <string.h>

int* findCoins(int* numWays, int numWaysSize, int* returnSize) {
    int* dp = (int*)calloc(numWaysSize + 1, sizeof(int));
    int* coins = (int*)malloc(sizeof(int) * numWaysSize);
    int coinCount = 0;
    dp[0] = 1;

    for (int i = 0; i < numWaysSize; ++i) {
        int amount = i + 1;
        int expected = numWays[i];

        if (expected > 0 && dp[amount] == expected - 1) {
            coins[coinCount++] = amount;
            for (int j = amount; j <= numWaysSize; ++j) {
                dp[j] += dp[j - amount];
            }
        }

        if (dp[amount] != expected) {
            free(dp);
            free(coins);
            *returnSize = 0;
            return NULL;
        }
    }

    free(dp);
    *returnSize = coinCount;
    return coins;
}
