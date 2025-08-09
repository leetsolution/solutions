class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        int powerOf2 = 1;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i == powerOf2) {
                powerOf2 *= 2;
                count = 0;
            }
            ans[i] = ans[count] + 1;
            count++;
        }
        return ans;
    }
}