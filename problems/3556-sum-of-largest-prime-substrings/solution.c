#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long sumOfLargestPrimes(char* s) {
    int len = strlen(s);
    long long primes[1024];
    int primeCount = 0;
    bool found[10000] = {false};

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            char sub[12] = {0};
            strncpy(sub, s + i, j - i + 1);
            long long num = atoll(sub);

            if (num > 0 && num < 10000 && isPrime(num) && !found[num]) {
                primes[primeCount++] = num;
                found[num] = true;
            }
        }
    }

    if (primeCount == 0) return 0;

    for (int i = 0; i < primeCount - 1; i++) {
        for (int j = i + 1; j < primeCount; j++) {
            if (primes[i] < primes[j]) {
                long long temp = primes[i];
                primes[i] = primes[j];
                primes[j] = temp;
            }
        }
    }

    long long sum = 0;
    int count = 0;
    for (int i = 0; i < primeCount && count < 3; i++) {
        sum += primes[i];
        count++;
    }

    return sum;
}