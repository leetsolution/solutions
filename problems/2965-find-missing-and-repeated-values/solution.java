class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int maxVal = n * n;
        int[] freq = new int[maxVal + 1];

        for (int[] row : grid) {
            for (int val : row) {
                freq[val]++;
            }
        }

        int[] ans = new int[2];
        for (int i = 1; i <= maxVal; i++) {
            if (freq[i] == 2) {
                ans[0] = i;
            } else if (freq[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
}