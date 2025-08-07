import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        k = k % (m * n);

        List<List<Integer>> shiftedGrid = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            shiftedGrid.add(new ArrayList<>());
            for (int j = 0; j < n; j++) {
                shiftedGrid.get(i).add(0);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newIndex = (i * n + j + k) % (m * n);
                int newRow = newIndex / n;
                int newCol = newIndex % n;
                shiftedGrid.get(newRow).set(newCol, grid[i][j]);
            }
        }

        return shiftedGrid;
    }
}