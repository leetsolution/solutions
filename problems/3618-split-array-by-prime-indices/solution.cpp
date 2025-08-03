class Solution {
public:
    long long splitArray(vector<int>& nums) {
    class Solution {
    public:
        bool isPrime(int n) {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) return false;
            }
            return true;
        }
        int sumDifference(vector<int>& nums) {
            long long sumA = 0;
            long long sumB = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (isPrime(i + 1)) {
                    sumA += nums[i];
                } else {
                    sumB += nums[i];
                }
            }
            return abs(sumA - sumB);
        }
    };
};