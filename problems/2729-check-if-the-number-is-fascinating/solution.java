class Solution {
    public boolean isFascinating(int n) {
        String s = Integer.toString(n) + Integer.toString(2 * n) + Integer.toString(3 * n);
        if (s.length() != 9) {
            return false;
        }
        int[] count = new int[10];
        for (int i = 0; i < 9; i++) {
            int digit = s.charAt(i) - '0';
            if (digit == 0) {
                return false;
            }
            count[digit]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (count[i] != 1) {
                return false;
            }
        }
        return true;
    }
}