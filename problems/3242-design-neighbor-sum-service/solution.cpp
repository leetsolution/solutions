class NeighborSum {
private:
    vector<vector<int>> grid;
    int n;
    pair<int, int> findValue(int value) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == value) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

public:
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
    }
    
    int adjacentSum(int value) {
        pair<int, int> pos = findValue(value);
        int row = pos.first;
        int col = pos.second;
        int sum = 0;

        if (row > 0) sum += grid[row - 1][col];
        if (row < n - 1) sum += grid[row + 1][col];
        if (col > 0) sum += grid[row][col - 1];
        if (col < n - 1) sum += grid[row][col + 1];

        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int, int> pos = findValue(value);
        int row = pos.first;
        int col = pos.second;
        int sum = 0;

        if (row > 0 && col > 0) sum += grid[row - 1][col - 1];
        if (row > 0 && col < n - 1) sum += grid[row - 1][col + 1];
        if (row < n - 1 && col > 0) sum += grid[row + 1][col - 1];
        if (row < n - 1 && col < n - 1) sum += grid[row + 1][col + 1];

        return sum;
    }
};