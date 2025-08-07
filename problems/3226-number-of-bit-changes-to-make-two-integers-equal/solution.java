class Solution {
    public int minChanges(int n, int k) {
        int xor = n ^ k;
        int count = 0;
        if (n < k) {
            return -1;
        }
        while (xor > 0) {
            if ((xor & 1) == 1) {
                if ((n & 1) == 1) {
                    count++;
                } else {
                    return -1;
                }
            }
            n >>= 1;
            k >>= 1;
            xor >>= 1;
        }
        return count;
    }
}