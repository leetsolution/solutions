bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right) {
    int n = rangesSize;
    int coverage[51] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
            coverage[j] = 1;
        }
    }
    for (int i = left; i <= right; i++) {
        if (coverage[i] == 0) {
            return false;
        }
    }
    return true;
}