class Solution {
    public boolean isThree(int n) {
        if (n < 4) return false;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
        return count == 3;
    }
}