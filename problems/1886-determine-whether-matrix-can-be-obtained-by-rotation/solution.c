bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int n = matSize;
    int rotations = 0;
    while (rotations < 4) {
        bool equal = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) {
                    equal = false;
                    break;
                }
            }
            if (!equal) break;
        }
        if (equal) return true;
        int** rotated = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            rotated[i] = (int*)malloc(n * sizeof(int));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - 1 - i] = mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = rotated[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            free(rotated[i]);
        }
        free(rotated);
        rotations++;
    }
    return false;
}