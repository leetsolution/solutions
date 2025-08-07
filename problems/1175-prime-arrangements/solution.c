int numPrimeArrangements(int n) {
    int prime_count = 0;
    for (int i = 2; i <= n; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            prime_count++;
        }
    }
    long long prime_factorial = 1;
    for (int i = 1; i <= prime_count; i++) {
        prime_factorial = (prime_factorial * i) % 1000000007;
    }
    long long non_prime_factorial = 1;
    for (int i = 1; i <= (n - prime_count); i++) {
        non_prime_factorial = (non_prime_factorial * i) % 1000000007;
    }
    return (int)((prime_factorial * non_prime_factorial) % 1000000007);
}