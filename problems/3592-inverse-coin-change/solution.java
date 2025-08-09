import java.util.*;

class Solution {
    public List<Integer> findCoins(int[] numWays) {
        List<Integer> coins = new ArrayList<>();
        int n = numWays.length;

        if (n == 0) {
            return coins;
        }

        if (numWays[0] != 1) {
            return new ArrayList<>();
        }

        for (int i = 1; i <= n; ++i) {
            List<Integer> currentCoins = new ArrayList<>(coins);
            currentCoins.add(i);

            int[] calculatedNumWays = calculateNumWays(n, currentCoins);

            boolean match = true;
            for (int j = 0; j <= n; ++j) {
                if (numWays[j] != calculatedNumWays[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                Collections.sort(currentCoins);
                List<Integer> uniqueCoins = new ArrayList<>();
                for (Integer coin : currentCoins) {
                    if (!uniqueCoins.contains(coin)) {
                        uniqueCoins.add(coin);
                    }
                }
                return uniqueCoins;
            }

            currentCoins = new ArrayList<>(coins);
            
            int[] tempCalc = calculateNumWaysPartial(n, currentCoins);
            if (numWays[1] == 2 && currentCoins.isEmpty()){
                currentCoins.add(1);
                currentCoins.add(2);
                 tempCalc = calculateNumWaysPartial(n, currentCoins);
               
                 
                
                boolean partMatch = true;
                for (int j = 0; j <= n; ++j) {
                    int expected = numWays[j];
                    int actual = tempCalc[j];
                     if (expected != actual) {
                        partMatch = false;
                        break;
                    }
                }
                    if(partMatch)
                    {
                         Collections.sort(currentCoins);
                         List<Integer> uniqueCoins = new ArrayList<>();
                         for (Integer coin : currentCoins) {
                             if (!uniqueCoins.contains(coin)) {
                                uniqueCoins.add(coin);
                             }
                         }
                         return uniqueCoins;
                    }
            }


            if(coins.isEmpty() && numWays.length > 1 && numWays[1] > 0 && numWays[1] == 2)
            {

                currentCoins = new ArrayList<>();
                currentCoins.add(1);
                currentCoins.add(2);
                tempCalc = calculateNumWaysPartial(n, currentCoins);

                 boolean partMatch = true;
                for (int j = 0; j <= n; ++j) {
                    int expected = numWays[j];
                    int actual = tempCalc[j];
                     if (expected != actual) {
                        partMatch = false;
                        break;
                    }
                }
                    if(partMatch)
                    {
                         Collections.sort(currentCoins);
                         List<Integer> uniqueCoins = new ArrayList<>();
                         for (Integer coin : currentCoins) {
                             if (!uniqueCoins.contains(coin)) {
                                uniqueCoins.add(coin);
                             }
                         }
                         return uniqueCoins;
                    }
            }



           boolean possible = true;
             currentCoins = new ArrayList<>();

           if(coins.isEmpty())
           {
                boolean found = false;
               
                for(int j = 1; j <= n; j++)
                {
                     currentCoins = new ArrayList<>();
                    if(numWays[j] > 0 && numWays[1] == 1){
                       
                           currentCoins.add(1);
                       
                           for(int k =2; k<=n; k++)
                           {

                               if(numWays[k] > 0)
                               {
                                   currentCoins.add(k);
                               }
                           }

                       
                       
                        tempCalc = calculateNumWaysPartial(n, currentCoins);
                         partMatch = true;
                        for (int l = 0; l <= n; ++l) {
                            int expected = numWays[l];
                            int actual = tempCalc[l];

                             if (expected != actual) {

                                partMatch = false;
                                break;
                            }
                        }
                         if(partMatch)
                            {
                                 Collections.sort(currentCoins);
                                 List<Integer> uniqueCoins = new ArrayList<>();
                                 for (Integer coin : currentCoins) {
                                     if (!uniqueCoins.contains(coin)) {
                                        uniqueCoins.add(coin);
                                     }
                                 }
                                 return uniqueCoins;
                            }
                           
                            
                    }

                   
                }

           }

           

        }

        return new ArrayList<>();
    }

    private int[] calculateNumWays(int n, List<Integer> coins) {
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= n; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp;
    }


    private int[] calculateNumWaysPartial(int n, List<Integer> coins) {
         int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= n; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp;
    }
}