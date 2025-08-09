class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        fill(image, sr, sc, color, originalColor);
        return image;
    }

    private void fill(int[][] image, int sr, int sc, int color, int originalColor) {
        int m = image.length;
        int n = image[0].length;
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor) return;
        image[sr][sc] = color;
        fill(image, sr + 1, sc, color, originalColor);
        fill(image, sr - 1, sc, color, originalColor);
        fill(image, sr, sc + 1, color, originalColor);
        fill(image, sr, sc - 1, color, originalColor);
    }
}