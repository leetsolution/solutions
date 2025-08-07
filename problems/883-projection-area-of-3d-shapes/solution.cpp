class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy_area = 0;
        int yz_area = 0;
        int zx_area = 0;

        for (int i = 0; i < n; ++i) {
            int yz_max = 0;
            int zx_max = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) xy_area++;
                yz_max = max(yz_max, grid[j][i]);
                zx_max = max(zx_max, grid[i][j]);
            }
            yz_area += yz_max;
            zx_area += zx_max;
        }
        return xy_area + yz_area + zx_area;
    }
};