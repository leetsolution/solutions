class Solution {
    public int diagonalPrime(int[][] nums) {
        int maxPrime = 0;
        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i][i])) {
                maxPrime = Math.max(maxPrime, nums[i][i]);
            }
            if (isPrime(nums[i][nums.length - i - 1])) {
                maxPrime = Math.max(maxPrime, nums[i][nums.length - i - 1]);
            }
        }
        return maxPrime;
    }

    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}