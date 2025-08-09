class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int distance = 0;
        while (xorVal > 0) {
            distance += xorVal & 1;
            xorVal >>= 1;
        }
        return distance;
    }
};