bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    for (int i = 0; i < n; i++) {
        bool row_present[n + 1];
        bool col_present[n + 1];

        for (int j = 0; j <= n; j++) {
            row_present[j] = false;
            col_present[j] = false;
        }

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] >= 1 && matrix[i][j] <= n) {
                row_present[matrix[i][j]] = true;
            } else {
                return false;
            }

            if (matrix[j][i] >= 1 && matrix[j][i] <= n) {
                col_present[matrix[j][i]] = true;
            } else {
                return false;
            }
        }

        for (int k = 1; k <= n; k++) {
            if (!row_present[k] || !col_present[k]) {
                return false;
            }
        }
    }

    return true;
}