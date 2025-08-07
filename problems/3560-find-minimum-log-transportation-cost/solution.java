class Solution {
    public long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        }

        long ans = Long.MAX_VALUE;

        if (n > k) {
            long cost1 = (long) (n - k) * k;
            if (n - k <= k) {
                if (n - k + m <= k) return cost1;
                if (m > k) {
                    long cost2 = (long)(m - k) * k;
                    return cost1 + cost2;
                }
                if (m <= k){
                     return cost1;
                }
               
            } else {
                long cost2 = (long)(n - k) * (n - (n - k));
                 if (m > k) {
                    long cost3 = (long)(m - k) * k;
                    return Long.min(ans,cost1 + cost2 + cost3);
                }
                  return Long.min(ans,cost1 + cost2);
            }
        }

        if (m > k) {
            long cost1 = (long) (m - k) * k;
            if (m - k <= k) {
                return cost1;
            } else {
                 long cost2 = (long)(m - k) * (m - (m - k));
                  return cost1+ cost2;
            }
        }


         if (n > k) {
            long cost1 = (long) (n - k) * k;
            if(n - k <=k) ans = Math.min(ans,cost1);
              else{
                   ans = Math.min(ans, (long) (n - k) * k + (long)(n-k) * (n - (n -k)));
              }
         }
         if (m > k) {
            long cost1 = (long) (m - k) * k;
             if(m-k <= k) ans = Math.min(ans,cost1);
            else{
                 ans = Math.min(ans,(long) (m - k) * k + (long)(m-k) * (m - (m -k)));
            }
         }
         if(n > k && m > k){
             long c1 = (long)(n-k) * k;
             long c2 = (long)(m-k) * k;

             if(n-k <= k && m-k <=k){
                return c1 + c2;
             }else if (n-k <= k) {
                 return c1 + (long)(m-k) * (m - (m -k));
             }else if (m-k <=k){
                return c2 + (long)(n-k) * (n - (n -k));
             }
             else{
                 return Math.min(ans, (long)(n-k) * (n - (n -k)) + (long)(m-k) * (m - (m -k)) + c1 + c2);
             }

         }


        if(n > k) ans = Math.min(ans,(long) (n - k) * k);
        if(m > k) ans = Math.min(ans, (long) (m - k) * k);
        return ans;
    }
}