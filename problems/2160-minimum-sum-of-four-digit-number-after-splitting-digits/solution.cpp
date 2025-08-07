class Solution {
public:
    int minimumSum(int num) {
        int digits[4];
        digits[0] = num / 1000;
        digits[1] = (num % 1000) / 100;
        digits[2] = (num % 100) / 10;
        digits[3] = num % 10;
        std::sort(digits, digits + 4);
        return (digits[0] + digits[1]) * 10 + digits[2] + digits[3];
    }
};