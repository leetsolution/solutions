class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int largestPrime = 0;
        for (int i = 0; i < n; ++i) {
            int val1 = nums[i][i];
            if (isPrime(val1)) {
                largestPrime = max(largestPrime, val1);
            }
            int val2 = nums[i][n - i - 1];
            if (isPrime(val2)) {
                largestPrime = max(largestPrime, val2);
            }
        }
        return largestPrime;
    }

    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};