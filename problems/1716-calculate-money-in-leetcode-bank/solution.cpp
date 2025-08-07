class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = 0;
        total += weeks * 28 + weeks * (weeks - 1) * 7 / 2;
        total += (days * (days + 1)) / 2 + weeks * days;
        return total;
    }
};