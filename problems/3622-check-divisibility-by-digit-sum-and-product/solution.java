class Solution {
    public boolean checkDivisibility(int n) {
        int sumOfDigits = 0;
        int productOfDigits = 1;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;
            sumOfDigits += digit;
            productOfDigits *= digit;
            temp /= 10;
        }

        return (n % (sumOfDigits + productOfDigits) == 0);
    }
}