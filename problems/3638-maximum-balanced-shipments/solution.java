class Solution {
    public int maxBalancedShipments(int[] weight) {
        int n = weight.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            int maxWeight = weight[i - 1];
            for (int j = i - 1; j >= 1; j--) {
                maxWeight = Math.max(maxWeight, weight[j - 1]);
                if (weight[i - 1] < maxWeight) {
                    dp[i] = Math.max(dp[i], dp[j - 1] + 1);
                }
            }
            if (weight[i-1] < weight[i-1]) {
                dp[i] = Math.max(dp[i], dp[i - 1] + 1);
            }
        }

        return dp[n];
    }
}