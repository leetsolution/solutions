int countPrimeSetBits(int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        int setBits = 0;
        int n = i;
        while (n > 0) {
            setBits += n & 1;
            n >>= 1;
        }
        if (setBits == 2 || setBits == 3 || setBits == 5 || setBits == 7 || setBits == 11 || setBits == 13 || setBits == 17 || setBits == 19) {
            count++;
        }
    }
    return count;
}