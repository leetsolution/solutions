int maxHeightOfTriangle(int red, int blue) {
    int low = 0, high = 100000;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long totalBalls = (long long)mid * (mid + 1) / 2;

        if (totalBalls > (red + blue)) {
            high = mid - 1;
            continue;
        }

        long long redNeeded = 0;
        bool possible = false;

        for (int i = 0; i <= mid; ++i) {
            redNeeded = (long long)i * (i + 1) / 2;
            if (redNeeded <= red && (totalBalls - redNeeded) <= blue) {
                possible = true;
                break;
            }
        }

        if (possible) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}