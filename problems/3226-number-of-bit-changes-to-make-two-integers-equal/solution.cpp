class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        int xor_val = n ^ k;
        if (n < k) return -1;
        while (xor_val > 0) {
            if ((xor_val & 1) == 1 && (n & 1) == 1) {
                changes++;
            } else if ((xor_val & 1) == 1 && (n & 1) == 0) {
                return -1;
            }
            xor_val >>= 1;
            n >>= 1;
        }
        return changes;
    }
};