int mySqrt(int x) {
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    long long start = 1, end = x / 2, ans = 0;

    while (start <= end) {
        long long mid = start + (end - start) / 2;
        long long sq = mid * mid;

        if (sq == x)
            return (int)mid;
        else if (sq < x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return (int)ans;
}