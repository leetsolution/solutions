class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins;
        int n = numWays.size();

        if (numWays[0] != 1) {
            return {};
        }

        for (int i = 1; i <= n; ++i) {
            bool possible = true;
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            vector<int> current_coins = coins;
            current_coins.push_back(i);
            sort(current_coins.begin(), current_coins.end());

            for (int amount = 1; amount <= n; ++amount) {
                for (int coin : current_coins) {
                    if (amount >= coin) {
                        dp[amount] += dp[amount - coin];
                    }
                }
            }
            
            for(int j = 1; j <= n; ++j) {
                if (dp[j] != numWays[j]) {
                    possible = false;
                    break;
                }
            }
            
            vector<int> temp_dp(n + 1, 0);
            temp_dp[0] = 1;

            for(int amount = 1; amount <= n; ++amount) {
                for(int coin_index = 0; coin_index < coins.size(); ++coin_index){
                    if(amount >= coins[coin_index]){
                        temp_dp[amount] += temp_dp[amount - coins[coin_index]];
                    }
                }
            }
            if(possible){
                coins.push_back(i);
                sort(coins.begin(), coins.end());

                vector<int> verify_dp(n+1, 0);
                verify_dp[0] = 1;

                for(int amount = 1; amount <= n; ++amount){
                    for(int coin : coins){
                        if(amount >= coin){
                            verify_dp[amount] += verify_dp[amount - coin];
                        }
                    }
                }

                bool verified = true;
                for(int j = 1; j <= n; ++j){
                    if(verify_dp[j] != numWays[j]){
                        verified = false;
                        coins.pop_back();
                        sort(coins.begin(), coins.end());
                        break;
                    }
                }

                if(!verified){
                    continue;
                }
            }
            

        }

        sort(coins.begin(), coins.end());
        return coins;
    }
};