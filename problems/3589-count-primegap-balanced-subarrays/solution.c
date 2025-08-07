#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 10000
#define MAX_LEN 100005

bool* generatePrimes(int max_val) {
    int N = 5 * max_val + 1;
    bool* isPrime = (bool*)malloc(sizeof(bool) * N);
    memset(isPrime, true, sizeof(bool) * N);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

void insertPrimeDQ(int* minDQ, int* maxDQ, int* minFront, int* minBack, int* maxFront, int* maxBack, int* nums, int idx) {
    while (*minBack > *minFront && nums[minDQ[(*minBack) - 1]] > nums[idx]) (*minBack)--;
    minDQ[(*minBack)++] = idx;

    while (*maxBack > *maxFront && nums[maxDQ[(*maxBack) - 1]] < nums[idx]) (*maxBack)--;
    maxDQ[(*maxBack)++] = idx;
}

int primeSubarray(int* nums, int numsSize, int k) {
    bool* isPrime = generatePrimes(MAX_NUM);

    int minDQ[MAX_LEN], maxDQ[MAX_LEN], primeDQ[MAX_LEN];
    int minFront = 0, minBack = 0, maxFront = 0, maxBack = 0, primeFront = 0, primeBack = 0;

    int left = 0, prevPrime = 0, result = 0;

    for (int i = 0; i < numsSize; i++) {
        int ele = nums[i];
        if (isPrime[ele]) {
            insertPrimeDQ(minDQ, maxDQ, &minFront, &minBack, &maxFront, &maxBack, nums, i);

            if (primeBack > primeFront) {
                prevPrime = primeDQ[primeBack - 1];
            }
            primeDQ[primeBack++] = i;

            while (nums[maxDQ[maxFront]] - nums[minDQ[minFront]] > k) {
                int tempIdx = primeDQ[primeFront++];
                left = tempIdx + 1;

                if (minFront < minBack && minDQ[minFront] <= tempIdx) minFront++;
                if (maxFront < maxBack && maxDQ[maxFront] <= tempIdx) maxFront++;
            }
        }

        if (primeBack - primeFront >= 2) {
            result += prevPrime - left + 1;
        }
    }

    free(isPrime);
    return result;
}
