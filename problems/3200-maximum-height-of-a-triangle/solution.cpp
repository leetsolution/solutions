class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int l = 0, r = 20000;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long total = (long long)mid * (mid + 1) / 2;
            if (total > (long long)red + blue) {
                r = mid - 1;
                continue;
            }
            long long red_needed = 0;
            for (int i = 1; i <= mid; ++i) {
                if (i % 2 == 1) {
                    red_needed += i;
                }
            }
            if (red_needed <= red && total - red_needed <= blue) {
                ans = mid;
                l = mid + 1;
                continue;
            }
            red_needed = 0;
            for (int i = 1; i <= mid; ++i) {
                if (i % 2 == 0) {
                    red_needed += i;
                }
            }
            if (red_needed <= red && total - red_needed <= blue) {
                ans = mid;
                l = mid + 1;
                continue;
            }
            r = mid - 1;
        }
        return ans;
    }
};