int minChanges(int n, int k) {
    int changes = 0;
    int xor_result = n ^ k;
    if (n < k) return -1;
    while (xor_result > 0) {
        if ((xor_result & 1) == 1 && (n & 1) == 1) {
            changes++;
        } else if ((xor_result & 1) == 1 && (n & 1) == 0) {
            return -1;
        }
        xor_result >>= 1;
        n >>= 1;
    }
    return changes;
}