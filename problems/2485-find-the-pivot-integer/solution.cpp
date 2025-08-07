class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int currentSum = 0;
        for (int x = 1; x <= n; ++x) {
            currentSum += x;
            if (currentSum == totalSum - currentSum + x) {
                return x;
            }
        }
        return -1;
    }
};