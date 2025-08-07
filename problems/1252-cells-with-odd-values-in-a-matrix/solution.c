int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < indicesSize; i++) {
        int r = indices[i][0];
        int c = indices[i][1];

        for (int j = 0; j < n; j++) {
            matrix[r][j]++;
        }

        for (int j = 0; j < m; j++) {
            matrix[j][c]++;
        }
    }

    int oddCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 != 0) {
                oddCount++;
            }
        }
    }

    return oddCount;
}