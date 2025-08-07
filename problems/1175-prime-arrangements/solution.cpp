class Solution {
public:
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        long long result = 1;
        long long nonPrimeCount = n - primeCount;
        long long mod = 1e9 + 7;
        for (long long i = 1; i <= primeCount; ++i) {
            result = (result * i) % mod;
        }
        for (long long i = 1; i <= nonPrimeCount; ++i) {
            result = (result * i) % mod;
        }
        return (int)result;
    }
};