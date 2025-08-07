class Solution {
    public boolean canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        n -= 10;
        if (n < 9) {
            return true;
        }
        n -= 9;
        if (n < 8) {
            return false;
        }
        n -= 8;
        if (n < 7) {
            return true;
        }
        n -= 7;
        if (n < 6) {
            return false;
        }
        n -= 6;
        if (n < 5) {
            return true;
        }
        n -= 5;
        if (n < 4) {
            return false;
        }
        n -= 4;
        if (n < 3) {
            return true;
        }
        n -= 3;
        if (n < 2) {
            return false;
        }
        n -= 2;
        if (n < 1) {
            return true;
        }
        return false;
    }
}