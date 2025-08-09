class Solution {
    public int countCells(char[][] grid, String pattern) {
        int m = grid.length;
        int n = grid[0].length;
        int patternLength = pattern.length();
        boolean[][] horizontal = new boolean[m][n];
        boolean[][] vertical = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                while (k < patternLength) {
                    int currentRow = i + (j + k) / n;
                    int currentCol = (j + k) % n;
                    if (currentRow >= m || grid[currentRow][currentCol] != pattern.charAt(k)) {
                        break;
                    }
                    k++;
                }
                if (k == patternLength) {
                    for (int l = 0; l < patternLength; l++) {
                        int currentRow = i + (j + l) / n;
                        int currentCol = (j + l) % n;
                        horizontal[currentRow][currentCol] = true;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                int k = 0;
                while (k < patternLength) {
                    int currentCol = j + (i + k) / m;
                    int currentRow = (i + k) % m;
                    if (currentCol >= n || grid[currentRow][currentCol] != pattern.charAt(k)) {
                        break;
                    }
                    k++;
                }
                if (k == patternLength) {
                    for (int l = 0; l < patternLength; l++) {
                        int currentCol = j + (i + l) / m;
                        int currentRow = (i + l) % m;
                        vertical[currentRow][currentCol] = true;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (horizontal[i][j] && vertical[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
}