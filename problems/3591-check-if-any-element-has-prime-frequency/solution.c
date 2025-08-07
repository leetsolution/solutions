bool checkPrimeFrequency(int* nums, int numsSize) {
    int counts[101] = {0};
    for (int i = 0; i < numsSize; i++) {
        counts[nums[i]]++;
    }

    int freq_counts[101] = {0};
    for (int i = 0; i <= 100; i++) {
        if (counts[i] > 0) {
            freq_counts[counts[i]]++;
        }
    }

    for (int i = 2; i <= 100; i++) {
        if (freq_counts[i] > 0) {
            int is_prime = 1;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
            if (is_prime) {
                return true;
            }
        }
    }
    return false;
}