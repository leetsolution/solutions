class Solution {
    public long popcountDepth(long n, int k) {
    class Solution {
        public long countIntegers(long n, int k) {
            long count = 0;
            for (long i = 1; i <= n; i++) {
                if (getPopcountDepth(i) == k) {
                    count++;
                }
            }
            return count;
        }

        private int getPopcountDepth(long n) {
            int depth = 0;
            while (n != 1) {
                n = Integer.bitCount((int) n);
                depth++;
            }
            return depth;
        }
    }
}