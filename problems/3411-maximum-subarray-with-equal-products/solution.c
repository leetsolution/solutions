#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int maxLength(int* nums, int numsSize) {
    int maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            long long prod = 1;
            int currentGcd = nums[i];
            int currentLcm = nums[i];
            for (int k = i; k <= j; k++) {
                prod *= nums[k];
                currentGcd = gcd(currentGcd, nums[k]);
                currentLcm = lcm(currentLcm, nums[k]);
            }

            if (prod == (long long)currentGcd * currentLcm) {
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                }
            }
        }
    }
    return maxLen;
}