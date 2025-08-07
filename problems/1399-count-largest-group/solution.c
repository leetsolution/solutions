int countLargestGroup(int n) {
    int count[37] = {0};
    int maxCount = 0;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        count[sum]++;
        if (count[sum] > maxCount) {
            maxCount = count[sum];
            result = 1;
        } else if (count[sum] == maxCount) {
            result++;
        }
    }

    return result;
}