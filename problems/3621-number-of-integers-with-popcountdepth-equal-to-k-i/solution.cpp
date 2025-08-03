class Solution {
public:
    long long popcountDepth(long long n, int k) {
    #include <iostream>

    int countSetBits(long long n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    int getPopcountDepth(long long n) {
        int depth = 0;
        while (n != 1) {
            n = countSetBits(n);
            depth++;
        }
        return depth;
    }

    long long countIntegers(long long n, int k) {
        long long count = 0;
        for (long long i = 1; i <= n; ++i) {
            if (getPopcountDepth(i) == k) {
                count++;
            }
        }
        return count;
    }
};