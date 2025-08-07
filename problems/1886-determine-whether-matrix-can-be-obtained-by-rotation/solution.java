class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int i = 0; i < 4; ++i) {
            boolean equal = true;
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (mat[r][c] != target[r][c]) {
                        equal = false;
                        break;
                    }
                }
                if (!equal) break;
            }
            if (equal) return true;
            int[][] temp = new int[n][n];
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    temp[c][n - 1 - r] = mat[r][c];
                }
            }
            mat = temp;
        }
        return false;
    }
}