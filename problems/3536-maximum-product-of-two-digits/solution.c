int maxProduct(int n) {
    int max1 = 0;
    int max2 = 0;
    int temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        if (digit > max1) {
            max2 = max1;
            max1 = digit;
        } else if (digit > max2) {
            max2 = digit;
        }
        temp /= 10;
    }

    if(max2 == 0) return max1 * max1;

    return max1 * max2;
}