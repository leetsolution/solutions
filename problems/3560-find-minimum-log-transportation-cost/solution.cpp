class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if (n > k) {
            cost += (long long)(n - k) * (k);
        }
        if (m > k) {
            cost += (long long)(m - k) * (k);
        }
        return cost;
    }
};