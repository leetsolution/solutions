long long splitArray(int* nums, int numsSize) {
    long long sumA = 0;
    long long sumB = 0;

    if (numsSize <= 0) {
        return 0;
    }

    for (int i = 0; i < numsSize; i++) {
        int isPrime = 1;
        if (i <= 1) {
            isPrime = 0;
        } else {
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime) {
            sumA += nums[i];
        } else {
            sumB += nums[i];
        }
    }

    return llabs(sumA - sumB);
}