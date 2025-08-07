class Solution {
public:
    string concatHex36(int n) {
        long long sq = (long long)n * n;
        long long cube = (long long)n * n * n;

        string hex_str = "";
        string hexatrigesimal_str = "";

        while (sq > 0) {
            int rem = sq % 16;
            if (rem < 10) {
                hex_str = to_string(rem) + hex_str;
            } else {
                hex_str = (char)('A' + (rem - 10)) + hex_str;
            }
            sq /= 16;
        }
        if (hex_str == "") hex_str = "0";

        while (cube > 0) {
            int rem = cube % 36;
            if (rem < 10) {
                hexatrigesimal_str = to_string(rem) + hexatrigesimal_str;
            } else {
                hexatrigesimal_str = (char)('A' + (rem - 10)) + hexatrigesimal_str;
            }
            cube /= 36;
        }
        if (hexatrigesimal_str == "") hexatrigesimal_str = "0";

        return hex_str + hexatrigesimal_str;
    }
};