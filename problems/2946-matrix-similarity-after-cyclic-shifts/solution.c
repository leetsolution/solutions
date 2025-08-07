bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];
    int** original = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        original[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            original[i][j] = mat[i][j];
        }
    }

    for (int step = 0; step < k; step++) {
        int** temp = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            temp[i] = (int*)malloc(n * sizeof(int));
        }
        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    temp[i][j] = mat[i][(j + 1) % n];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    temp[i][j] = mat[i][(j + n - 1) % n];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = temp[i][j];
            }
            free(temp[i]);
        }
        free(temp);
    }
    bool similar = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != original[i][j]) {
                similar = false;
                break;
            }
        }
        free(original[i]);
        if (!similar) break;
    }
    free(original);
    return similar;
}