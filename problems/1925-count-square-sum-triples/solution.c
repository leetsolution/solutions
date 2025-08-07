int countTriples(int n) {
    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            long long c_squared = (long long)a * a + (long long)b * b;
            long long c = sqrt(c_squared);
            if (c * c == c_squared && c <= n) {
                count++;
            }
        }
    }
    return count;
}