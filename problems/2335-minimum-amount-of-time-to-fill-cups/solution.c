int fillCups(int* amount, int amountSize) {
    int max1 = amount[0];
    int max2 = amount[1];
    int max3 = amount[2];
    if (max2 > max1) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }
    if (max3 > max1) {
        int temp = max1;
        max1 = max3;
        max3 = temp;
    }
    if (max3 > max2) {
        int temp = max2;
        max2 = max3;
        max3 = temp;
    }

    int sum = amount[0] + amount[1] + amount[2];
    int max_val = max1;

    if (2 * max_val > sum) {
        return max_val;
    } else {
        return (sum + 1) / 2;
    }
}