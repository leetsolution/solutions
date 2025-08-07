class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length;
        int xyArea = 0;
        int yzArea = 0;
        int zxArea = 0;

        for (int i = 0; i < n; i++) {
            int yzMax = 0;
            int zxMax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    xyArea++;
                }
                yzMax = Math.max(yzMax, grid[j][i]);
                zxMax = Math.max(zxMax, grid[i][j]);
            }
            yzArea += yzMax;
            zxArea += zxMax;
        }
        return xyArea + yzArea + zxArea;
    }
}