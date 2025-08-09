int maxBalancedShipments(int* weight, int weightSize) {
    int dp[weightSize + 1];
    dp[0] = 0;

    for (int i = 1; i <= weightSize; i++) {
        dp[i] = dp[i - 1];
        int maxWeight = weight[i - 1];
        for (int j = i - 1; j >= 1; j--) {
            if (weight[j - 1] > maxWeight) {
                maxWeight = weight[j - 1];
            }
            if (weight[i - 1] < maxWeight) {
                dp[i] = (dp[i] > dp[j - 1] + 1) ? dp[i] : (dp[j - 1] + 1);
            }
        }
        if (weight[i - 1] < maxWeight) {
          dp[i] = (dp[i] > 1) ? dp[i] : 1;
        }
    }

    return dp[weightSize];
}