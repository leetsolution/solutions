int countBalls(int lowLimit, int highLimit) {
    int counts[46] = {0};
    int maxCount = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        int sum = 0;
        int num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        counts[sum]++;
        if (counts[sum] > maxCount) {
            maxCount = counts[sum];
        }
    }
    return maxCount;
}