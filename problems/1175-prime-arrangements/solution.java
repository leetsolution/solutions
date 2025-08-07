class Solution {
    public int numPrimeArrangements(int n) {
        int primeCount = 0;
        boolean[] isPrime = new boolean[n + 1];
        java.util.Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        long result = 1;
        long mod = 1000000007;
        for (int i = 1; i <= primeCount; i++) {
            result = (result * i) % mod;
        }
        for (int i = 1; i <= n - primeCount; i++) {
            result = (result * i) % mod;
        }
        return (int) result;
    }
}