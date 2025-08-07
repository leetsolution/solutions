class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int lastOne = -1;
        int currentBit = 0;

        while (n > 0) {
            if (n % 2 == 1) {
                if (lastOne != -1) {
                    maxGap = max(maxGap, currentBit - lastOne);
                }
                lastOne = currentBit;
            }
            n /= 2;
            currentBit++;
        }

        return maxGap;
    }
};