class Solution {
    public int maxBalancedShipments(int[] weight) {
    class Solution {
        public int maximumBalancedShipments(int[] weight) {
            int n = weight.length;
            int count = 0;
            int i = 0;
            while (i < n) {
                int max = 0;
                int j = i;
                while (j < n) {
                    max = Math.max(max, weight[j]);
                    if (weight[j] < max) {
                        count++;
                        i = j + 1;
                        break;
                    }
                    j++;
                }
                if (j == n) {
                    break;
                }

            }
            return count;
        }
    }
}