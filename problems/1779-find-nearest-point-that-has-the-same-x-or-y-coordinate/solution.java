class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int minDistance = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int i = 0; i < points.length; i++) {
            int a = points[i][0];
            int b = points[i][1];

            if (a == x || b == y) {
                int distance = Math.abs(x - a) + Math.abs(y - b);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = i;
                }
            }
        }

        return minIndex;
    }
}