class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = bits.length - 2;
        while (i >= 0 && bits[i] == 1) {
            i--;
        }
        return (bits.length - 1 - i) % 2 == 0;
    }
}