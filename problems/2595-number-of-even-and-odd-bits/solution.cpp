class Solution {
public:
    vector<int> evenOddBit(int n) {
        string binary = "";
        int temp = n;
        while (temp > 0) {
            binary = (temp % 2 == 0 ? "0" : "1") + binary;
            temp /= 2;
        }
        int even = 0;
        int odd = 0;
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                if ((i + 1) % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }
        return {even, odd};
    }
};