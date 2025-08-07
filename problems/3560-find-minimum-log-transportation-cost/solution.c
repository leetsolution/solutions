long long minCuttingCost(int n, int m, int k) {
    if (n <= k && m <= k) {
        return 0;
    }

    if (n > k && m > k) {
        return (long long)(n - k) * k + (long long)(m - k) * k;
    }

    if (n > k) {
        if (n - k + m <= k) {
            return (long long)(n - k) * k;
        } else {
            return (long long)(n - k) * k + (long long)(m - (k - (n - k))) * (k - (n - k));
        }
    } else {
        if (m - k + n <= k) {
            return (long long)(m - k) * k;
        } else {
            return (long long)(m - k) * k + (long long)(n - (k - (m - k))) * (k - (m - k));
        }
    }
}