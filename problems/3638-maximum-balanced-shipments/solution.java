class Solution {
    public int maxBalancedShipments(int[] weight) {
        int n = weight.length;
        int count = 0;
        int i = 0;
        while (i < n) {
            int max = weight[i];
            int j = i;
            boolean found = false;
            while (j < n) {
                max = Math.max(max, weight[j]);
                if (weight[j] < max) {
                    count++;
                    i = j + 1;
                    found = true;
                    break;
                }
                j++;
            }
            if (!found) break;
        }
        return count;
    }
}