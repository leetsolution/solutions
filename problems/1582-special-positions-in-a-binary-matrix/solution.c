int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                int row_sum = 0;
                for (int k = 0; k < n; k++) {
                    row_sum += mat[i][k];
                }

                if (row_sum == 1) {
                    int col_sum = 0;
                    for (int k = 0; k < m; k++) {
                        col_sum += mat[k][j];
                    }

                    if (col_sum == 1) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}