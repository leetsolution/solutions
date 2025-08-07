import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> zigzagTraversal(int[][] grid) {
        List<Integer> result = new ArrayList<>();
        int m = grid.length;
        int n = grid[0].length;
        boolean right = true;

        for (int i = 0; i < m; i++) {
            if (right) {
                for (int j = 0; j < n; j += 2) {
                    result.add(grid[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; j -= 2) {
                    result.add(grid[i][j]);
                }
            }
            right = !right;
        }

        return result;
    }
}