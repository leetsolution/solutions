import java.util.Arrays;

class Solution {
    public int fillCups(int[] amount) {
        Arrays.sort(amount);
        int a = amount[0], b = amount[1], c = amount[2];
        if (a + b <= c) {
            return c;
        } else {
            return (a + b + c + 1) / 2;
        }
    }
}