int arrangeCoins(int n) {
    long long left = 0, right = n;
    long long k;
    while (left <= right) {
        k = left + (right - left) / 2;
        long long coins = k * (k + 1) / 2;
        if (coins == n) return (int)k;
        else if (coins < n) left = k + 1;
        else right = k - 1;
    }
    return (int)right;
}