import java.util.HashMap;
import java.util.Map;

class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int winCount = 0;
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> colorCount = new HashMap<>();
            for (int[] p : pick) {
                if (p[0] == i) {
                    colorCount.put(p[1], colorCount.getOrDefault(p[1], 0) + 1);
                }
            }
            boolean win = false;
            for (int count : colorCount.values()) {
                if (count >= i + 1) {
                    win = true;
                    break;
                }
            }
            if (win) {
                winCount++;
            }
        }
        return winCount;
    }
}