import java.util.*;

class Solution {
    public static List<Integer> findCoins(int[] numWays) {
        int n = numWays.length;
        int[] dp = new int[n + 1];
        List<Integer> coins = new ArrayList<>();
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            int amount = i + 1;
            int expectedWays = numWays[i];

            if (expectedWays > 0 && dp[amount] == expectedWays - 1) {
                coins.add(amount);
                for (int j = amount; j <= n; j++) {
                    dp[j] += dp[j - amount];
                }
            }

            if (dp[amount] != expectedWays) {
                return new ArrayList<>();
            }
        }

        return coins;
    }
}
