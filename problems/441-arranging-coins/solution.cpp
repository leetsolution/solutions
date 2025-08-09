class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0, r = n;
        long long ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum <= n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (int)ans;
    }
};