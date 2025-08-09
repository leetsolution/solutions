class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long sumA = 0;
        long long sumB = 0;
        int n = nums.size();

        if (n == 0) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p < n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += p)
                    isPrime[i] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                sumA += nums[i];
            } else {
                sumB += nums[i];
            }
        }

        return abs(sumA - sumB);
    }
};