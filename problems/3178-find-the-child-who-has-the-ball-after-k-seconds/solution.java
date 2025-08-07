class Solution {
    public int numberOfChild(int n, int k) {
        int period = (n - 1) * 2;
        k %= period;
        if (k < n) {
            return k;
        } else {
            return n - (k - (n - 1)) - 1;
        }
    }
}