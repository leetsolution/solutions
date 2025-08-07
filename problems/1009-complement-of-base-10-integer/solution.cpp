class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int num_bits = 0;
        int temp = n;
        while (temp > 0) {
            temp >>= 1;
            num_bits++;
        }
        int mask = (1 << num_bits) - 1;
        return n ^ mask;
    }
};