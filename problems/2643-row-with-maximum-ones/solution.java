class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int maxOnes = 0;
        int rowIndex = 0;
        for (int i = 0; i < mat.length; i++) {
            int currentOnes = 0;
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 1) {
                    currentOnes++;
                }
            }
            if (currentOnes > maxOnes) {
                maxOnes = currentOnes;
                rowIndex = i;
            }
        }
        return new int[]{rowIndex, maxOnes};
    }
}