int buyChoco(int* prices, int pricesSize, int money) {
    int min1 = 101;
    int min2 = 101;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }
    if (min1 + min2 <= money) {
        return money - (min1 + min2);
    } else {
        return money;
    }
}