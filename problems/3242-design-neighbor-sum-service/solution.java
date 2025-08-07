class NeighborSum {
    private int[][] grid;
    private int n;

    public NeighborSum(int[][] grid) {
        this.grid = grid;
        this.n = grid.length;
    }

    public int adjacentSum(int value) {
        int row = -1, col = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        int sum = 0;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int[] dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                sum += grid[newRow][newCol];
            }
        }

        return sum;
    }

    public int diagonalSum(int value) {
        int row = -1, col = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        int sum = 0;
        int[][] directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (int[] dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                sum += grid[newRow][newCol];
            }
        }

        return sum;
    }
}