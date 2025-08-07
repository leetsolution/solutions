class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] original = new int[m][n];
        for (int i = 0; i < m; i++) {
            System.arraycopy(mat[i], 0, original[i], 0, n);
        }
        int[][] temp = new int[m][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                System.arraycopy(mat[j], 0, temp[j], 0, n);
            }
            for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                    int first = temp[j][0];
                    for (int l = 0; l < n - 1; l++) {
                        mat[j][l] = temp[j][l + 1];
                    }
                    mat[j][n - 1] = first;
                } else {
                    int last = temp[j][n - 1];
                    for (int l = n - 1; l > 0; l--) {
                        mat[j][l] = temp[j][l - 1];
                    }
                    mat[j][0] = last;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != original[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}