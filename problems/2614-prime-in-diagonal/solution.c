int diagonalPrime(int** nums, int numsSize, int* numsColSize) {
    int maxPrime = 0;

    int isPrime(int n) {
        if (n <= 1) return 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return 0;
        }
        return 1;
    }

    for (int i = 0; i < numsSize; i++) {
        int val1 = nums[i][i];
        if (isPrime(val1)) {
            if (val1 > maxPrime) {
                maxPrime = val1;
            }
        }

        int val2 = nums[i][numsSize - 1 - i];
        if (isPrime(val2)) {
            if (val2 > maxPrime) {
                maxPrime = val2;
            }
        }
    }

    return maxPrime;
}