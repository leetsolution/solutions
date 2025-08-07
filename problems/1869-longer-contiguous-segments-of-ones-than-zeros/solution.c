bool checkZeroOnes(char* s) {
    int max_ones = 0;
    int current_ones = 0;
    int max_zeros = 0;
    int current_zeros = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            current_ones++;
            current_zeros = 0;
        } else {
            current_zeros++;
            current_ones = 0;
        }
        max_ones = (current_ones > max_ones) ? current_ones : max_ones;
        max_zeros = (current_zeros > max_zeros) ? current_zeros : max_zeros;
    }
    return max_ones > max_zeros;
}