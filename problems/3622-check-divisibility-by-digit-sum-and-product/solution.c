bool checkDivisibility(int n) {
    int sum = 0;
    int product = 1;
    int temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }

    if (sum + product == 0) {
        return false;
    }

    return (n % (sum + product) == 0);
}