class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;
        while (i >= 0 && bits[i] == 1) {
            i -= 1;
        }
        return (bits.size() - 1 - i) % 2 == 0;
    }
};