class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int height = grid[i][j];
                if (height > 0) {
                    totalArea += 2; // Top and bottom surface area
                    totalArea += max(0, height - (i > 0 ? grid[i - 1][j] : 0));
                    totalArea += max(0, height - (i < n - 1 ? grid[i + 1][j] : 0));
                    totalArea += max(0, height - (j > 0 ? grid[i][j - 1] : 0));
                    totalArea += max(0, height - (j < n - 1 ? grid[i][j + 1] : 0));
                }
            }
        }
        return totalArea;
    }
};