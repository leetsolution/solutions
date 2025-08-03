class Solution {
    public long splitArray(int[] nums) {
    class Solution {
        public int splitArrayByPrimeIndices(int[] nums) {
            long sumA = 0;
            long sumB = 0;

            for (int i = 0; i < nums.length; i++) {
                if (isPrime(i + 1)) {
                    sumA += nums[i];
                } else {
                    sumB += nums[i];
                }
            }

            return (int) Math.abs(sumA - sumB);
        }

        private boolean isPrime(int n) {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) return false;
            }
            return true;
        }
    }
}