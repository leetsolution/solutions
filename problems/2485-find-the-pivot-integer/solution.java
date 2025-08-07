class Solution {
    public int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int leftSum = 0;
        for (int x = 1; x <= n; x++) {
            leftSum += x;
            if (leftSum == totalSum - leftSum + x) {
                return x;
            }
        }
        return -1;
    }
}